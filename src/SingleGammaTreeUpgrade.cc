#include "SingleGammaTreeUpgrade.h"
#include <TString.h>
#include <TObjArray.h>
#include <TMath.h>
#include <iostream>
#include <vector>
#include <TVector3.h>
#include <TH1.h>

using std::cout;
using std::endl;


SingleGammaTreeUpgrade::SingleGammaTreeUpgrade(TTree *tree, const TString& outname) : tree_reader_up(tree)
{  
  hOutputFile = TFile::Open(outname, "RECREATE" ) ;
}


SingleGammaTreeUpgrade::~SingleGammaTreeUpgrade() {
  
  hOutputFile->Write() ;
  hOutputFile->Close() ;
  hOutputFile->Delete();
}


vector<int> SingleGammaTreeUpgrade::firstones(Float_t *vec, vector<bool> *asso, int number){
  
  vector<int> themax;
  
  for(int j=0; j<number; j++) {
    double maxtemp(-999); 
    int idmaxtemp(-999);

    for (int i=0; i<int(asso->size()); i++) {
      bool skip(0);
      for(int ss=0; ss<j; ss++) { 
	if ( i == themax.at(ss) )   
	  skip = 1;
      }
      if ( vec[i] > maxtemp && asso->at(i) && !skip) {
	maxtemp = vec[i];
	idmaxtemp = i;
      }
    }
    themax.push_back(idmaxtemp);
  }
  return themax;
}


void SingleGammaTreeUpgrade::Loop() {

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;

  hOutputFile->cd();   
  TH1D ptphotgen1("ptphotgen1","ptphotgen1", 100, 0.,300.);
  

  //********************************************************
  // tree initialization
  int nPhot_presel, nPhot_gen;
  
  float deltaRMatch_gen[50];
  float iRecoPhotMatch_gen[50];
  float ptRecoMatch_gen[50];
  float ptTrueMatch_gen[50];
  float etaMatch_gen[50];
  float phiMatch_gen[50];

  float ptPhot_presel[50];
  float ePhot_presel[50];
  float phiPhot_presel[50];
  float etaPhot_presel[50];

  int isMatchedPhot[50];
  int iMatchedPhot[50];

  float e4_presel[50];
  float e9_presel[50];
  float e25_presel[50];

  float pid_scetawid_presel[50];
  float pid_scphiwid_presel[50]; 
  float sEtaEtaPhot_presel[50];
  float sEtaPhiPhot_presel[50];
  float s4RatioPhot_presel[50];
  float r9Phot_presel[50];
  float etascPhot_presel[50];
  float rr_presel[50];
  float pid_lambdaRatio_presel[50];
  float pid_HoverE_presel[50];

  int val_pho_isconv_presel[50];

  float pid_jurECAL03_presel[50];
  float pid_twrHCAL03_presel[50];
  float pid_hlwTrack03_presel[50];
  float pid_jurECAL04_presel[50];
  float pid_twrHCAL04_presel[50];
  float pid_hlwTrack04_presel[50];
  
  float pid_pfIsoCharged03ForCiC_presel[50];
  float pid_pfIsoCharged04ForCiC_presel[50];
  float pid_pfIsoPhotons03ForCiC_presel[50];
  float pid_pfIsoPhotons04ForCiC_presel[50];
  float pid_pfIsoNeutrals03ForCiC_presel[50];
  float pid_pfIsoNeutrals04ForCiC_presel[50];

  ana_tree = new TTree ("AnaTree","Reduced tree for final analysis");

  // general
  ana_tree->Branch("run",  &runRN,  "run/I");
  ana_tree->Branch("event",&eventRN,"event/I");
  ana_tree->Branch("lumi", &lumi,   "lumi/I");
  ana_tree->Branch("nvtx", &nvtx,   "nvtx/F");

  ana_tree->Branch("LOGamma",    &LOGamma,    "LOGamma/I");
  ana_tree->Branch("ISRGamma",   &ISRGamma,   "ISRGamma/I");
  ana_tree->Branch("FSRGamma",   &FSRGamma,   "FSRGamma/I");

  ana_tree->Branch("npu",       &npu,       "npu/I");
  
  // gen level photons
  ana_tree->Branch("nPhot_gen",          &nPhot_gen,         "nPhot_gen/I");  
  ana_tree->Branch("ptTrueMatch_gen",    ptTrueMatch_gen,    "ptTrueMatch_gen[nPhot_gen]/F");
  ana_tree->Branch("etaMatch_gen",       etaMatch_gen,       "etaMatch_gen[nPhot_gen]/F");
  ana_tree->Branch("phiMatch_gen",       phiMatch_gen,       "phiMatch_gen[nPhot_gen]/F");
  ana_tree->Branch("deltaRMatch_gen",    deltaRMatch_gen,    "deltaRMatch_gen[nPhot_gen]/F");
  ana_tree->Branch("ptRecoMatch_gen",    ptRecoMatch_gen,    "ptRecoMatch_gen[nPhot_gen]/F");
  ana_tree->Branch("iRecoPhotMatch_gen", iRecoPhotMatch_gen, "iRecoPhotMatch_gen[nPhot_gen]/F");

  // reco photons
  ana_tree->Branch("nPhot_presel",    &nPhot_presel,   "nPhot_presel/I");
  ana_tree->Branch("ptPhot_presel",   ptPhot_presel,   "ptPhot_presel[nPhot_presel]/F");
  ana_tree->Branch("ePhot_presel",    ePhot_presel,    "ePhot_presel[nPhot_presel]/F");
  ana_tree->Branch("etascPhot_presel",etascPhot_presel,"etascPhot_presel[nPhot_presel]/F");
  ana_tree->Branch("etaPhot_presel",  etaPhot_presel,  "etaPhot[nPhot_presel]/F");
  ana_tree->Branch("phiPhot_presel",  phiPhot_presel,  "phiPhot[nPhot_presel]/F");

  ana_tree->Branch("pid_jurECAL03_presel", pid_jurECAL03_presel, "pid_jurECAL03_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_twrHCAL03_presel", pid_twrHCAL03_presel, "pid_twrHCAL03_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_hlwTrack03_presel",pid_hlwTrack03_presel,"pid_hlwTrack03_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_jurECAL04_presel", pid_jurECAL04_presel, "pid_jurECAL04_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_twrHCAL04_presel", pid_twrHCAL04_presel, "pid_twrHCAL04_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_hlwTrack04_presel",pid_hlwTrack04_presel,"pid_hlwTrack04_presel[nPhot_presel]/F");	
  
  ana_tree->Branch("pid_pfIsoCharged03ForCiC_presel", pid_pfIsoCharged03ForCiC_presel, "pid_pfIsoCharged03ForCiC_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_pfIsoCharged04ForCiC_presel", pid_pfIsoCharged04ForCiC_presel, "pid_pfIsoCharged04ForCiC_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_pfIsoPhotons03ForCiC_presel", pid_pfIsoPhotons03ForCiC_presel, "pid_pfIsoPhotons03ForCiC_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_pfIsoPhotons04ForCiC_presel", pid_pfIsoPhotons04ForCiC_presel, "pid_pfIsoPhotons04ForCiC_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_pfIsoNeutrals03ForCiC_presel",pid_pfIsoNeutrals03ForCiC_presel,"pid_pfIsoNeutrals03ForCiC_presel[nPhot_presel]/F");
  ana_tree->Branch("pid_pfIsoNeutrals04ForCiC_presel",pid_pfIsoNeutrals04ForCiC_presel,"pid_pfIsoNeutrals04ForCiC_presel[nPhot_presel]/F");
		
  ana_tree->Branch("e4_presel",   e4_presel,   "e4_presel[nPhot_presel]/F");	
  ana_tree->Branch("e9_presel",   e9_presel,   "e9_presel[nPhot_presel]/F");	
  ana_tree->Branch("e25_presel",  e25_presel,  "e25_presel[nPhot_presel]/F");	

  ana_tree->Branch("pid_scetawid_presel",   pid_scetawid_presel,   "pid_scetawid_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_scphiwid_presel",   pid_scphiwid_presel,   "pid_scphiwid_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_lambdaRatio_presel",pid_lambdaRatio_presel,"pid_lambdaRatio_presel[nPhot_presel]/F");	
  ana_tree->Branch("pid_HoverE_presel",     pid_HoverE_presel,     "pid_HoverE_presel[nPhot_presel]/F");	
  ana_tree->Branch("sEtaEtaPhot_presel",    sEtaEtaPhot_presel,    "sEtaEtaPhot_presel[nPhot_presel]/F");	
  ana_tree->Branch("sEtaPhiPhot_presel",    sEtaPhiPhot_presel,    "sEtaPhiPhot_presel[nPhot_presel]/F");	
  ana_tree->Branch("s4RatioPhot_presel",    s4RatioPhot_presel,    "s4RatrioPhot_presel[nPhot_presel]/F"); 
  ana_tree->Branch("r9Phot_presel",         r9Phot_presel,         "r9Phot_presel[nPhot_presel]/F"); 
  ana_tree->Branch("rr_presel",             rr_presel,             "rr_presel[nPhot_presel]/F"); 

  ana_tree->Branch("val_pho_isconv_presel", val_pho_isconv_presel, "val_pho_isconv_presel[nPhot_presel]/I");

  // info about matching gen gamma 
  ana_tree->Branch("isMatchedPhot", isMatchedPhot, "isMatchedPhot[nPhot_presel]/I");
  ana_tree->Branch("iMatchedPhot",  iMatchedPhot,  "iMatchedPhot[nPhot_presel]/I");

  ana_tree->Branch("rhoAllJets",&rhoAllJets,"rhoAllJets/F");	
  ana_tree->Branch("rhoPF",     &rhoPF,     "rhoPF/F");	

  // vertex
  ana_tree->Branch("vtxId",     &vtxId,     "vtxId/I");



  
  // Initializations
  TString foldname("");
  TString currfilename("");
  int ifile(0);
  int nfiles = ((TChain*)fChain)->GetListOfFiles()->GetEntries();
  
  int nprocessed = 0;
  int nredntp    = 0;
    

  
  // --------------------------------------------------------------
  // Loop
  for (Long64_t jentry=0; jentry<nentries;jentry++) {

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    nprocessed++;
    if (nprocessed%1000 == 0) cout << "Events " << nprocessed << " processed; Run " << run << " LS " << lbn << endl;


    // ------------------------------------  
    // print name of current file
    currfilename = TString(fChain->GetCurrentFile()->GetName());
    if(currfilename != foldname) {
      ifile++;
      cout << "Opening file " << ifile << " of "  << nfiles << "\n"
	   << currfilename  << "\n"
	   << "------------------------------"
	   << endl;
      foldname = currfilename;
    }


    // ------------------------------------
    // pile-up
    npu = pu_n;

    // ------------------------------------
    // skip events where the number of jets, photons, and vertexes is above the maximum allowed value
    if (nPhot>50) {
      cout << "number of photons = " << nPhot << " and above threshold of 50; skipping" << endl;
      continue;
    }
    if (nJet_pfakt5 > 200) {
      cout << "number of nJet_pfakt5 = " << nJet_pfakt5 << " and above threshold of 200; skipping" << endl;
      continue;
    }
    if (nJetGen_akt5 > 200) {
      cout << "number of nJetGen_akt5 = " << nJetGen_akt5 << " and above threshold of 200; skipping" << endl;
      continue;
    }


    // --------------------------------------------------------------
    // GEN LEVEL analysis
    int nGenPhot(0);
    vector<bool> photassocMC;
    for(int i=0; i<nMC; i++) {
      
      if((pdgIdMC[i] == 22 && statusMC[i] == 3) //photon in the diagram
	 || (pdgIdMC[i] == 22 && statusMC[i] == 1 && (TMath::Abs(pdgIdMC[motherIDMC[i]])<=10 ) ) //photon coming from a quark
	 ) {
	
	photassocMC.push_back(1);	
	ptTrueMatch_gen[nGenPhot] = ptMC[i];
	etaMatch_gen[nGenPhot]    = etaMC[i];
	phiMatch_gen[nGenPhot]    = phiMC[i];

	TVector3 gen;
	gen.SetPtEtaPhi(ptMC[i], etaMC[i], phiMC[i]);

	float deltaRmin = 0.3;
	int i_nPhot=-1;
	for(int j=0; j<nPhot; j++) {
	  TVector3 reco;
	  reco.SetPtEtaPhi(ptPhot[j],etaPhot[j],phiPhot[j]);
	  if(gen.DeltaR(reco) < deltaRmin) {
	    deltaRmin = gen.DeltaR(reco);
	    i_nPhot = j;
	  }
	}
	
	if (i_nPhot>-1) {
	  deltaRMatch_gen[nGenPhot] = deltaRmin;
	  ptRecoMatch_gen[nGenPhot] = ptPhot[i_nPhot];
	  iRecoPhotMatch_gen[nGenPhot] = i_nPhot;
	} else {
	  deltaRMatch_gen[nGenPhot] = -999.;
	  ptRecoMatch_gen[nGenPhot] = -999.;
	  iRecoPhotMatch_gen[nGenPhot] = -999;
	}

	nGenPhot++;
      }
      else
	photassocMC.push_back(0);
    }
    nPhot_gen = nGenPhot;

    // gen level gammas
    vector<int> firstfourgenphot = firstones(ptMC,&photassocMC,4);

    // to be used after
    ptphotgen1.Fill(ptMC[firstfourgenphot.at(0)]);
    



    
    // reconstructed variables -----------------------------------------
    int countPreselPhot = 0;  
    vector<bool> preselPhot;

    for (int i=0; i<nPhot; i++) {
    
      // preselection: acceptance and minimal pT cut
      if( ! (ptPhot[i]>10 && ((TMath::Abs(etascPhot[i]) < 1.4442) || (TMath::Abs(etascPhot[i]) > 1.566 && TMath::Abs(etascPhot[i]) < 2.5)) )) { 
	preselPhot.push_back(0);
	continue;
      }	  
      preselPhot.push_back(1);

      // kine variables
      ptPhot_presel[countPreselPhot]    = ptPhot[i];
      ePhot_presel[countPreselPhot]     = ePhot[i];
      etaPhot_presel[countPreselPhot]   = etaPhot[i];
      phiPhot_presel[countPreselPhot]   = phiPhot[i];
      etascPhot_presel[countPreselPhot] = etascPhot[i];

      // matrices
      e4_presel[countPreselPhot]  = E4Phot[i];
      e9_presel[countPreselPhot]  = E9Phot[i];
      e25_presel[countPreselPhot] = E25Phot[i];

      // id variables
      float r9phot = E9Phot[i] / escRawPhot[i];
      float s4phot = E4Phot[i] / E25Phot[i];
      s4RatioPhot_presel[countPreselPhot]  = s4phot; 
      r9Phot_presel[countPreselPhot]       = r9phot;
      pid_scetawid_presel[countPreselPhot] = pid_scetawid[i];
      pid_scphiwid_presel[countPreselPhot] = pid_scphiwid[i];
      sEtaEtaPhot_presel[countPreselPhot]  = pid_etawid[i];
      sEtaPhiPhot_presel[countPreselPhot]  = sEtaPhiPhot[i];
      pid_HoverE_presel[countPreselPhot]   = pid_HoverE[i];
      pid_lambdaRatio_presel[countPreselPhot] = pid_lambdaRatio[i]; 
      float rr2=0;
      if (isEEPhot) rr2=pid_esXwidth[i]*pid_esXwidth[i]+pid_esYwidth[i]*pid_esYwidth[i];
      rr_presel[countPreselPhot] = sqrt(rr2);

      // conversion safe electron veto
      val_pho_isconv_presel[countPreselPhot] = !hasMatchedPromptElePhot[i];    // must be true
      
      // iso variables
      pid_jurECAL03_presel[countPreselPhot] = pid_jurECAL03[i];
      pid_twrHCAL03_presel[countPreselPhot] = pid_twrHCAL03[i];
      pid_hlwTrack03_presel[countPreselPhot]= pid_hlwTrack03[i];
      pid_jurECAL04_presel[countPreselPhot] = pid_jurECAL[i];
      pid_twrHCAL04_presel[countPreselPhot] = pid_twrHCAL[i];
      pid_hlwTrack04_presel[countPreselPhot]= pid_hlwTrack[i];

      // PF iso variables
      pid_pfIsoPhotons03ForCiC_presel[countPreselPhot]  = pid_pfIsoPhotons03ForCiC[i]; 	   
      pid_pfIsoPhotons04ForCiC_presel[countPreselPhot]  = pid_pfIsoPhotons04ForCiC[i];	   
      pid_pfIsoNeutrals03ForCiC_presel[countPreselPhot] = pid_pfIsoNeutrals03ForCiC[i] ;	   
      pid_pfIsoNeutrals04ForCiC_presel[countPreselPhot] = pid_pfIsoNeutrals04ForCiC[i] ;	   
      pid_pfIsoCharged03ForCiC_presel[countPreselPhot]  = pid_pfIsoCharged03ForCiC[i][0];
      pid_pfIsoCharged04ForCiC_presel[countPreselPhot]  = pid_pfIsoCharged04ForCiC[i][0];

      // info about gen level matching
      isMatchedPhot[countPreselPhot] = 0;
      iMatchedPhot[countPreselPhot]  = -1;
      for(int igen=0; igen<nPhot_gen; igen++) {
	if (iRecoPhotMatch_gen[igen]==i ) {
	  isMatchedPhot[countPreselPhot] = 1;
	  iMatchedPhot[countPreselPhot] = igen;
	}	
      }
      
      countPreselPhot++;
    }
    nPhot_presel= countPreselPhot;



    // ----------------------------------------------------
    // various
    nvtx    = nvertex;
    runRN   = run;
    eventRN = event;
    lumi    = lbn;
    
    // check LO gammas - to remove duplicate events in different MC samples
    LOGamma  = countLOGenGamma();
    ISRGamma = countISRGenGamma();
    FSRGamma = countFSRGenGamma();
    
    // check if the first vertex is good
    vtxId=0;
    float rhoVtx=sqrt(vx[0]*vx[0]+vy[0]*vy[0]);
    if (vndof[0]<4 || fabs(vz[0])>24. || rhoVtx>2.) vtxId=-555;
    
    ana_tree->Fill();
  }
  
  ptphotgen1.Write();
  ana_tree->Write();
}

int SingleGammaTreeUpgrade::countLOGenGamma(){
  
  int totLO = 0;
  for (int ii=0; ii<nMC; ii++) {
    int myStatus = statusMC[ii];
    int myId     = pdgIdMC[ii];
    if (myStatus==3 && myId==22) {
      int myMoth   = motherIDMC[ii];
      int myMothId = abs(pdgIdMC[myMoth]);
      if (myMothId<=25) totLO++;   // quarks, gluons, W, Z and ZHiggs as mothers                  
    }
  }
  return totLO;
}

int SingleGammaTreeUpgrade::countISRGenGamma(){
  
  int totISR = 0;
  for (int ii=0; ii<nMC; ii++) {
    int myStatus = statusMC[ii];
    int myId     = pdgIdMC[ii];
    if (myStatus==1 && myId==22) {
      int myMoth   = motherIDMC[ii];
      int myMothId = abs(pdgIdMC[myMoth]);
      if (myMothId<11 || myMothId==21) totISR++;   // quarks and gluons as mothers                  
    }
  }
  return totISR;
}

int SingleGammaTreeUpgrade::countFSRGenGamma(){
  
  int totFSR = 0;
  for (int ii=0; ii<nMC; ii++) {
    int myStatus = statusMC[ii];
    int myId     = pdgIdMC[ii];
    if (myStatus==1 && myId==22) {
      int myMoth   = motherIDMC[ii];
      int myMothId = abs(pdgIdMC[myMoth]);
      if (myMothId>10 && myMothId<21) totFSR++;   // leptons as mothers                  
    }
  }
  return totFSR;
}
