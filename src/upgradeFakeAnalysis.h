//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May 16 15:56:09 2013 by ROOT version 5.32/00
// from TTree AnaTree/Reduced tree for final analysis
// found on file: /xrootdfs/cms/local/crovelli/GammaJets/reduced/redntp.53xv2.cicpfloose.noCorrections.GammaJets_newNtuples_v5/merged/redntp_G_Pt-120to170_TuneZ2star_8TeV_pythia6.root
//////////////////////////////////////////////////////////

#ifndef upgradeFakeAnalysis_h
#define upgradeFakeAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

class upgradeFakeAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

#include "RedNtpFormat.h"

   int effectiveAreaRegion(float theEta);
   float combinedPfIso03(float isoCharged03, float isoNeutral03, float isoPhoton03, float eta);
   float correctedPfIsoCharged03(float isoCharged03, float eta);
   float correctedPfIsoNeutrals03(float isoNeutral03, float eta);
   float correctedPfIsoPhotons03(float isoPhoton03, float eta);

   std::vector<int> sortedPtPhotons();
   std::vector<int> sortedPtGenPhotons();

   std::vector<int> preselectedPhotons(const std::vector<int>& photons);
   std::vector<int> selectedPhotonsLoose(const std::vector<int>& photons);
   std::vector<int> selectedPhotonsMedium(const std::vector<int>& photons);
   std::vector<int> selectedPhotonsTight(const std::vector<int>& photons);

   void BookHistos();
   void SaveHistos();

   TH1F *H_vtx;
   
   TH1F *H_matchedEB_convSafe, *H_matchedEB_HoE, *H_matchedEB_sIeIe;
   TH1F *H_matchedEB_uncIsoCh, *H_matchedEB_uncIsoNe, *H_matchedEB_uncIsoPh;
   TH1F *H_matchedEB_corIsoCh, *H_matchedEB_corIsoNe, *H_matchedEB_corIsoPh;
   TProfile *P_matchedEB_uncIsoChVsNvtx, *P_matchedEB_uncIsoNeVsNvtx, *P_matchedEB_uncIsoPhVsNvtx;
   TProfile *P_matchedEB_corIsoChVsNvtx, *P_matchedEB_corIsoNeVsNvtx, *P_matchedEB_corIsoPhVsNvtx;

   TH1F *H_matchedEE_convSafe, *H_matchedEE_HoE, *H_matchedEE_sIeIe;
   TH1F *H_matchedEE_uncIsoCh, *H_matchedEE_uncIsoNe, *H_matchedEE_uncIsoPh;
   TH1F *H_matchedEE_corIsoCh, *H_matchedEE_corIsoNe, *H_matchedEE_corIsoPh;
   TProfile *P_matchedEE_uncIsoChVsNvtx, *P_matchedEE_uncIsoNeVsNvtx, *P_matchedEE_uncIsoPhVsNvtx;
   TProfile *P_matchedEE_corIsoChVsNvtx, *P_matchedEE_corIsoNeVsNvtx, *P_matchedEE_corIsoPhVsNvtx;

   TH1F *H_unmatchedEB_convSafe, *H_unmatchedEB_HoE, *H_unmatchedEB_sIeIe;
   TH1F *H_unmatchedEB_uncIsoCh, *H_unmatchedEB_uncIsoNe, *H_unmatchedEB_uncIsoPh;
   TH1F *H_unmatchedEB_corIsoCh, *H_unmatchedEB_corIsoNe, *H_unmatchedEB_corIsoPh;

   TH1F *H_unmatchedEE_convSafe, *H_unmatchedEE_HoE, *H_unmatchedEE_sIeIe;
   TH1F *H_unmatchedEE_uncIsoCh, *H_unmatchedEE_uncIsoNe, *H_unmatchedEE_uncIsoPh;
   TH1F *H_unmatchedEE_corIsoCh, *H_unmatchedEE_corIsoNe, *H_unmatchedEE_corIsoPh;

   upgradeFakeAnalysis(TTree *tree=0);
   virtual ~upgradeFakeAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef upgradeFakeAnalysis_cxx
upgradeFakeAnalysis::upgradeFakeAnalysis(TTree *tree) : fChain(0) 
{
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("reducedNtuples/red_Ageing150_PU140.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("reducedNtuples/red_Ageing150_PU140.root");
    }
    f->GetObject("AnaTree",tree);
    
  }
  Init(tree);
}

upgradeFakeAnalysis::~upgradeFakeAnalysis()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t upgradeFakeAnalysis::GetEntry(Long64_t entry)
{
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Long64_t upgradeFakeAnalysis::LoadTree(Long64_t entry)
{
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void upgradeFakeAnalysis::Init(TTree *tree)
{
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);
  
  fChain->SetBranchAddress("run", &run, &b_run);
  fChain->SetBranchAddress("event", &event, &b_event);
  fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
  fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
  fChain->SetBranchAddress("LOGamma", &LOGamma, &b_LOGamma);
  fChain->SetBranchAddress("ISRGamma", &ISRGamma, &b_ISRGamma);
  fChain->SetBranchAddress("FSRGamma", &FSRGamma, &b_FSRGamma);
  fChain->SetBranchAddress("npu", &npu, &b_npu);
  fChain->SetBranchAddress("nPhot_gen", &nPhot_gen, &b_nPhot_gen);
  fChain->SetBranchAddress("deltaRMatch_gen", deltaRMatch_gen, &b_deltaRMatch_gen);
  fChain->SetBranchAddress("ptTrueMatch_gen", ptTrueMatch_gen, &b_ptTrueMatch_gen);
  fChain->SetBranchAddress("etaMatch_gen", etaMatch_gen, &b_etaMatch_gen);
  fChain->SetBranchAddress("phiMatch_gen", phiMatch_gen, &b_phiMatch_gen);
  fChain->SetBranchAddress("ptRecoMatch_gen", ptRecoMatch_gen, &b_ptRecoMatch_gen);
  fChain->SetBranchAddress("iRecoPhotMatch_gen", iRecoPhotMatch_gen, &b_iRecoPhotMatch_gen);
  fChain->SetBranchAddress("nPhot_presel", &nPhot_presel, &b_nPhot_presel);
  fChain->SetBranchAddress("ptPhot_presel", ptPhot_presel, &b_ptPhot_presel);
  fChain->SetBranchAddress("ePhot_presel", ePhot_presel, &b_ePhot_presel);
  fChain->SetBranchAddress("etascPhot_presel", etascPhot_presel, &b_etascPhot_presel  );
  fChain->SetBranchAddress("etaPhot_presel", etaPhot_presel, &b_etaPhot_presel);
  fChain->SetBranchAddress("phiPhot_presel", phiPhot_presel, &b_phiPhot_presel);
  fChain->SetBranchAddress("pid_jurECAL03_presel", pid_jurECAL03_presel, &b_pid_jurECAL03_presel);
  fChain->SetBranchAddress("pid_twrHCAL03_presel", pid_twrHCAL03_presel, &b_pid_twrHCAL03_presel);
  fChain->SetBranchAddress("pid_hlwTrack03_presel", pid_hlwTrack03_presel, &b_pid_hlwTrack03_presel);
  fChain->SetBranchAddress("pid_jurECAL04_presel", pid_jurECAL04_presel, &b_pid_jurECAL04_presel);
  fChain->SetBranchAddress("pid_twrHCAL04_presel", pid_twrHCAL04_presel, &b_pid_twrHCAL04_presel);
  fChain->SetBranchAddress("pid_hlwTrack04_presel", pid_hlwTrack04_presel, &b_pid_hlwTrack04_presel);
  fChain->SetBranchAddress("pid_pfIsoCharged03ForCiC_presel", pid_pfIsoCharged03ForCiC_presel, &b_pid_pfIsoCharged03ForCiC_presel);
  fChain->SetBranchAddress("pid_pfIsoCharged04ForCiC_presel", pid_pfIsoCharged04ForCiC_presel, &b_pid_pfIsoCharged04ForCiC_presel);
  fChain->SetBranchAddress("pid_pfIsoPhotons03ForCiC_presel", pid_pfIsoPhotons03ForCiC_presel, &b_pid_pfIsoPhotons03ForCiC_presel);
  fChain->SetBranchAddress("pid_pfIsoPhotons04ForCiC_presel", pid_pfIsoPhotons04ForCiC_presel, &b_pid_pfIsoPhotons04ForCiC_presel);
  fChain->SetBranchAddress("pid_pfIsoNeutrals03ForCiC_presel", pid_pfIsoNeutrals03ForCiC_presel, &b_pid_pfIsoNeutrals03ForCiC_presel);
  fChain->SetBranchAddress("pid_pfIsoNeutrals04ForCiC_presel", pid_pfIsoNeutrals04ForCiC_presel, &b_pid_pfIsoNeutrals04ForCiC_presel);
  fChain->SetBranchAddress("e4_presel",  e4_presel,  &b_e4_presel);
  fChain->SetBranchAddress("e9_presel",  e9_presel,  &b_e9_presel);
  fChain->SetBranchAddress("e25_presel", e25_presel, &b_e25_presel);
  fChain->SetBranchAddress("pid_scetawid_presel", pid_scetawid_presel, &b_pid_scetawid_presel);
  fChain->SetBranchAddress("pid_scphiwid_presel", pid_scphiwid_presel, &b_pid_scphiwid_presel);
  fChain->SetBranchAddress("pid_lambdaRatio_presel", pid_lambdaRatio_presel, &b_pid_lambdaRatio_presel);
  fChain->SetBranchAddress("pid_HoverE_presel", pid_HoverE_presel, &b_pid_HoverE_presel);
  fChain->SetBranchAddress("sEtaEtaPhot_presel", sEtaEtaPhot_presel, &b_sEtaEtaPhot_presel);
  fChain->SetBranchAddress("sEtaPhiPhot_presel", sEtaPhiPhot_presel, &b_sEtaPhiPhot_presel);
  fChain->SetBranchAddress("s4RatioPhot_presel", s4RatioPhot_presel, &b_s4RatioPhot_presel);
  fChain->SetBranchAddress("r9Phot_presel", r9Phot_presel, &b_r9Phot_presel);
  fChain->SetBranchAddress("rhoAllJets", &rhoAllJets, &b_rhoAllJets);
  fChain->SetBranchAddress("rhoPF", &rhoPF, &b_rhoPF);
  fChain->SetBranchAddress("rr_presel", rr_presel, &b_rr_presel);
  fChain->SetBranchAddress("isMatchedPhot", isMatchedPhot, &b_isMatchedPhot);
  fChain->SetBranchAddress("iMatchedPhot", iMatchedPhot, &b_iMatchedPhot);
  fChain->SetBranchAddress("val_pho_isconv_presel", val_pho_isconv_presel, &b_val_pho_isconv_presel);
  fChain->SetBranchAddress("vtxId", &vtxId, &b_vtxId);
  
  Notify();
}

Bool_t upgradeFakeAnalysis::Notify()
{
  return kTRUE;
}

void upgradeFakeAnalysis::Show(Long64_t entry)
{
  if (!fChain) return;
  fChain->Show(entry);
}

Int_t upgradeFakeAnalysis::Cut(Long64_t entry)
{
  return 1;
}
#endif // #ifdef upgradeFakeAnalysis_cxx
