#define upgradeFakeAnalysis_cxx
#include "upgradeFakeAnalysis.h"
#include <TMath.h>
#include <vector>
#include <iostream>

using namespace std;

void upgradeFakeAnalysis::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  
  // Initialize
  BookHistos();    
  
  Long64_t nbytes = 0, nb = 0;
  Long64_t npassing = 0; 

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    if (jentry%50000==0) 
      cout << "Analyzing event " << jentry << "/" << nentries << " (" << jentry*100./nentries << "%)" << endl;
    
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    
    // first vertex must be good
    if (vtxId<0) continue;
    
    // photon selection
    std::vector<int> photons          = sortedPtPhotons();    
    std::vector<int> preselectPhotons = preselectedPhotons(photons);
    std::vector<int> selectPhotonsL   = selectedPhotonsLoose(preselectPhotons);
    std::vector<int> selectPhotonsM   = selectedPhotonsMedium(preselectPhotons);
    std::vector<int> selectPhotonsT   = selectedPhotonsTight(preselectPhotons);

    // matched / unmatched gammas
    std::vector<int> matchedRecoPhot,   unmatchedRecoPhot;
    std::vector<int> matchedPreselPhot, unmatchedPreselPhot;
    std::vector<int> matchedSelPhotL,   unmatchedSelPhotL;
    std::vector<int> matchedSelPhotM,   unmatchedSelPhotM;
    std::vector<int> matchedSelPhotT,   unmatchedSelPhotT;
    
    // matching gen and reco photons 
    if (nPhot_gen<1) continue;
    std::vector<int> genPhotons=sortedPtGenPhotons();
    
    for(int ireco=0; ireco<(int)photons.size(); ireco++) {
      
      bool isRecoMatched = false;
      int theRecoG = photons[ireco];
      
      for (int igen=0; igen<(int)genPhotons.size(); igen++) {
	int theGenG = genPhotons[igen];
	if (theRecoG==iRecoPhotMatch_gen[theGenG]) { 
	  isRecoMatched = true;
	  break;
	}
      }
      
      if (isRecoMatched) 
	matchedRecoPhot.push_back(theRecoG);
      else
	unmatchedRecoPhot.push_back(theRecoG);
    }
    

    // checking if the matching gammas are preselected and selected => efficiencies
    for(int irecoM=0; irecoM<(int)matchedRecoPhot.size(); irecoM++) {
      int theRecoMG = matchedRecoPhot[irecoM];
      
      for(int j=0; j<(int)preselectPhotons.size(); j++) 
	if (preselectPhotons[j]==theRecoMG) matchedPreselPhot.push_back(theRecoMG);
      
      for(int j=0; j<(int)selectPhotonsL.size(); j++) 
	if (selectPhotonsL[j]==theRecoMG) matchedSelPhotL.push_back(theRecoMG);

      for(int j=0; j<(int)selectPhotonsM.size(); j++) 
	if (selectPhotonsM[j]==theRecoMG) matchedSelPhotM.push_back(theRecoMG);

      for(int j=0; j<(int)selectPhotonsT.size(); j++) 
	if (selectPhotonsT[j]==theRecoMG) matchedSelPhotT.push_back(theRecoMG);
    }


    // checking if the not matching gammas are preselected and selected => fakes
    for(int irecoUM=0; irecoUM<(int)unmatchedRecoPhot.size(); irecoUM++) {
      int theRecoUMG = unmatchedRecoPhot[irecoUM];
      
      for(int j=0; j<(int)preselectPhotons.size(); j++) 
	if (preselectPhotons[j]==theRecoUMG) unmatchedPreselPhot.push_back(theRecoUMG);
      
      for(int j=0; j<(int)selectPhotonsL.size(); j++) 
	if (selectPhotonsL[j]==theRecoUMG) unmatchedSelPhotL.push_back(theRecoUMG);

      for(int j=0; j<(int)selectPhotonsM.size(); j++) 
	if (selectPhotonsM[j]==theRecoUMG) unmatchedSelPhotM.push_back(theRecoUMG);

      for(int j=0; j<(int)selectPhotonsT.size(); j++) 
	if (selectPhotonsT[j]==theRecoUMG) unmatchedSelPhotT.push_back(theRecoUMG);
    }
  

    ++npassing;

    // Filling general histos
    H_vtx->Fill(nvtx);

    
    // Filling Histos for matched gammas
    for(int irecoM=0; irecoM<(int)matchedRecoPhot.size(); irecoM++) {
      
      int theRecoMG = matchedRecoPhot[irecoM];
      
      // corrections to isolation 
      float corrIsoCh = correctedPfIsoCharged03( pid_pfIsoCharged03ForCiC_presel[theRecoMG],  etascPhot_presel[theRecoMG]);
      float corrIsoNe = correctedPfIsoNeutrals03(pid_pfIsoNeutrals03ForCiC_presel[theRecoMG], etascPhot_presel[theRecoMG]);
      float corrIsoPh = correctedPfIsoPhotons03( pid_pfIsoPhotons03ForCiC_presel[theRecoMG],  etascPhot_presel[theRecoMG]);

      // EB/EE
      bool isBarrel = false;
      float etaSc = etascPhot_presel[theRecoMG];
      if (fabs(etaSc)<1.5) isBarrel=true;

      if (isBarrel) {

	H_matchedEB_convSafe -> Fill(val_pho_isconv_presel[theRecoMG]);
	H_matchedEB_HoE      -> Fill(pid_HoverE_presel[theRecoMG]);
	H_matchedEB_sIeIe    -> Fill(sEtaEtaPhot_presel[theRecoMG]);
	H_matchedEB_uncIsoCh -> Fill(pid_pfIsoCharged03ForCiC_presel[theRecoMG]);
	H_matchedEB_uncIsoNe -> Fill(pid_pfIsoNeutrals03ForCiC_presel[theRecoMG]);
	H_matchedEB_uncIsoPh -> Fill(pid_pfIsoPhotons03ForCiC_presel[theRecoMG]);
	H_matchedEB_corIsoCh -> Fill(corrIsoCh);
	H_matchedEB_corIsoNe -> Fill(corrIsoNe);
	H_matchedEB_corIsoPh -> Fill(corrIsoPh);

	// making profiles only with preselected gammas
	for(int iPresM=0; iPresM<(int)matchedPreselPhot.size(); iPresM++) {
	  if (matchedPreselPhot[iPresM]==theRecoMG) {
	    P_matchedEB_uncIsoChVsNvtx -> Fill(nvtx, pid_pfIsoCharged03ForCiC_presel[theRecoMG]);
	    P_matchedEB_uncIsoNeVsNvtx -> Fill(nvtx, pid_pfIsoNeutrals03ForCiC_presel[theRecoMG]);
	    P_matchedEB_uncIsoPhVsNvtx -> Fill(nvtx, pid_pfIsoPhotons03ForCiC_presel[theRecoMG]);
	    P_matchedEB_corIsoChVsNvtx -> Fill(nvtx, corrIsoCh);
	    P_matchedEB_corIsoNeVsNvtx -> Fill(nvtx, corrIsoNe);
	    P_matchedEB_corIsoPhVsNvtx -> Fill(nvtx, corrIsoPh);
	  }
	}

      } else {

	H_matchedEE_convSafe -> Fill(val_pho_isconv_presel[theRecoMG]);
	H_matchedEE_HoE      -> Fill(pid_HoverE_presel[theRecoMG]);
	H_matchedEE_sIeIe    -> Fill(sEtaEtaPhot_presel[theRecoMG]);
	H_matchedEE_uncIsoCh -> Fill(pid_pfIsoCharged03ForCiC_presel[theRecoMG]);
	H_matchedEE_uncIsoNe -> Fill(pid_pfIsoNeutrals03ForCiC_presel[theRecoMG]);
	H_matchedEE_uncIsoPh -> Fill(pid_pfIsoPhotons03ForCiC_presel[theRecoMG]);
	H_matchedEE_corIsoCh -> Fill(corrIsoCh);
	H_matchedEE_corIsoNe -> Fill(corrIsoNe);
	H_matchedEE_corIsoPh -> Fill(corrIsoPh);

	// making profiles only with preselected gammas
	for(int iPresM=0; iPresM<(int)matchedPreselPhot.size(); iPresM++) {
	  if (matchedPreselPhot[iPresM]==theRecoMG) {
	    P_matchedEE_uncIsoChVsNvtx -> Fill(nvtx, pid_pfIsoCharged03ForCiC_presel[theRecoMG]);
	    P_matchedEE_uncIsoNeVsNvtx -> Fill(nvtx, pid_pfIsoNeutrals03ForCiC_presel[theRecoMG]);
	    P_matchedEE_uncIsoPhVsNvtx -> Fill(nvtx, pid_pfIsoPhotons03ForCiC_presel[theRecoMG]);
	    P_matchedEE_corIsoChVsNvtx -> Fill(nvtx, corrIsoCh);
	    P_matchedEE_corIsoNeVsNvtx -> Fill(nvtx, corrIsoNe);
	    P_matchedEE_corIsoPhVsNvtx -> Fill(nvtx, corrIsoPh);
	  }
	}
      }
    }


    
    // Filling Histos for unmatched gammas
    for(int irecoUM=0; irecoUM<(int)unmatchedRecoPhot.size(); irecoUM++) {
      
      int theRecoUMG = unmatchedRecoPhot[irecoUM];
      
      // corrections to isolation 
      float corrIsoCh = correctedPfIsoCharged03(pid_pfIsoCharged03ForCiC_presel[theRecoUMG],  etascPhot_presel[theRecoUMG]);
      float corrIsoNe = correctedPfIsoNeutrals03(pid_pfIsoNeutrals03ForCiC_presel[theRecoUMG], etascPhot_presel[theRecoUMG]);
      float corrIsoPh = correctedPfIsoPhotons03(pid_pfIsoPhotons03ForCiC_presel[theRecoUMG],  etascPhot_presel[theRecoUMG]);

      // EB/EE
      bool isBarrel = false;
      float etaSc = etascPhot_presel[theRecoUMG];
      if (fabs(etaSc)<1.5) isBarrel=true;

      if (isBarrel) {
	H_unmatchedEB_convSafe -> Fill(val_pho_isconv_presel[theRecoUMG]);
	H_unmatchedEB_HoE      -> Fill(pid_HoverE_presel[theRecoUMG]);
	H_unmatchedEB_sIeIe    -> Fill(sEtaEtaPhot_presel[theRecoUMG]);
	H_unmatchedEB_uncIsoCh -> Fill(pid_pfIsoCharged03ForCiC_presel[theRecoUMG]);
	H_unmatchedEB_uncIsoNe -> Fill(pid_pfIsoNeutrals03ForCiC_presel[theRecoUMG]);
	H_unmatchedEB_uncIsoPh -> Fill(pid_pfIsoPhotons03ForCiC_presel[theRecoUMG]);
	H_unmatchedEB_corIsoCh -> Fill(corrIsoCh);
	H_unmatchedEB_corIsoNe -> Fill(corrIsoNe);
	H_unmatchedEB_corIsoPh -> Fill(corrIsoPh);
      } else {
	H_unmatchedEE_convSafe -> Fill(val_pho_isconv_presel[theRecoUMG]);
	H_unmatchedEE_HoE      -> Fill(pid_HoverE_presel[theRecoUMG]);
	H_unmatchedEE_sIeIe    -> Fill(sEtaEtaPhot_presel[theRecoUMG]);
	H_unmatchedEE_uncIsoCh -> Fill(pid_pfIsoCharged03ForCiC_presel[theRecoUMG]);
	H_unmatchedEE_uncIsoNe -> Fill(pid_pfIsoNeutrals03ForCiC_presel[theRecoUMG]);
	H_unmatchedEE_uncIsoPh -> Fill(pid_pfIsoPhotons03ForCiC_presel[theRecoUMG]);
	H_unmatchedEE_corIsoCh -> Fill(corrIsoCh);
	H_unmatchedEE_corIsoNe -> Fill(corrIsoNe);
	H_unmatchedEE_corIsoPh -> Fill(corrIsoPh);
      }
    }
    
    // qui va messo quanto serve x le ROC - chiara

  }  // loop over entries

  // Write output
  SaveHistos();    
}

// for effective area calculation
int upgradeFakeAnalysis::effectiveAreaRegion(float theEta) {

  int theEAregion = 999;
  if (fabs(theEta)<1.) theEAregion = 0;      
  if (fabs(theEta)<1.479 && fabs(theEta)>1.)    theEAregion = 1;
  if (fabs(theEta)<2.    && fabs(theEta)>1.479) theEAregion = 2;
  if (fabs(theEta)<2.2   && fabs(theEta)>2.0)   theEAregion = 3;
  if (fabs(theEta)<2.3   && fabs(theEta)>2.2)   theEAregion = 4;
  if (fabs(theEta)<2.4   && fabs(theEta)>2.3)   theEAregion = 5;
  if (fabs(theEta)>2.4) theEAregion = 6;
  return theEAregion;
}

std::vector<int> upgradeFakeAnalysis::preselectedPhotons(const std::vector<int>& photons) {
  
  // a minimal preselection (eta and pT>10) already applied at reduction level
  std::vector<int> selPhotons;
  
  for (int ipho=0;ipho<(int)photons.size();++ipho) {

    int recoP = photons[ipho];

    // EB/EE
    bool isBarrel = false;
    float etaSc = etascPhot_presel[recoP];
    if (fabs(etaSc)<1.5) isBarrel=true;

    // preselection from
    // https://indico.cern.ch/event/193674/material/slides/0?contribId=2
    if ( ptPhot_presel[recoP]<30 )       continue;   
    if ( pid_HoverE_presel[recoP]>0.05 ) continue;
    if ( isBarrel && sEtaEtaPhot_presel[recoP]>0.011 ) continue;
    if ( !isBarrel && sEtaEtaPhot_presel[recoP]>0.030) continue;

    selPhotons.push_back(photons[ipho]);
  }
  
  return selPhotons;
}

std::vector<int> upgradeFakeAnalysis::selectedPhotonsLoose(const std::vector<int>& photons) {

  std::vector<int> selPhotons;
  
  for (int ipho=0;ipho<(int)photons.size();++ipho) {

    int recoP = photons[ipho];
    
    // EB/EE
    bool isBarrel = false;
    float etaSc = etascPhot_presel[recoP];
    if (fabs(etaSc)<1.5) isBarrel=true;
    
    // electron veto
    if ( !val_pho_isconv_presel[recoP] ) continue;
    
    // identification
    if ( isBarrel ) {  
      if ( pid_HoverE_presel[recoP]>0.05 )   continue;
      if ( sEtaEtaPhot_presel[recoP]>0.012 ) continue;
    } else {     
      if(pid_HoverE_presel[recoP]>0.05)    continue;
      if (sEtaEtaPhot_presel[recoP]>0.034) continue;
    }

    // isolation 
    float corrIsoCh = correctedPfIsoCharged03(pid_pfIsoCharged03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    float corrIsoNe = correctedPfIsoNeutrals03(pid_pfIsoNeutrals03ForCiC_presel[recoP], etascPhot_presel[recoP]);
    float corrIsoPh = correctedPfIsoPhotons03(pid_pfIsoPhotons03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    if (isBarrel) {
      if ( corrIsoCh > 2.6) continue;
      if ( corrIsoNe > 3.5 + 0.04*ptPhot_presel[recoP])  continue;
      if ( corrIsoPh > 1.3 + 0.005*ptPhot_presel[recoP]) continue;
    } else {
      if ( corrIsoCh > 2.3) continue;
      if ( corrIsoNe > 2.9 + 0.04*ptPhot_presel[recoP]) continue;
      if ( corrIsoPh > 100000000) continue;
    }
    
    selPhotons.push_back(photons[ipho]);
  }
  return selPhotons;
}

std::vector<int> upgradeFakeAnalysis::selectedPhotonsMedium(const std::vector<int>& photons) {

  std::vector<int> selPhotons;
  
  for (int ipho=0;ipho<(int)photons.size();++ipho) {

    int recoP = photons[ipho];
    
    // EB/EE
    bool isBarrel = false;
    float etaSc = etascPhot_presel[recoP];
    if (fabs(etaSc)<1.5) isBarrel=true;
    
    // electron veto
    if ( !val_pho_isconv_presel[recoP] ) continue;
    
    // identification
    if ( isBarrel ) {  
      if ( pid_HoverE_presel[recoP]>0.05 )   continue;
      if ( sEtaEtaPhot_presel[recoP]>0.011 ) continue;
    } else {     
      if(pid_HoverE_presel[recoP]>0.05)    continue;
      if (sEtaEtaPhot_presel[recoP]>0.033) continue;
    }

    // isolation 
    float corrIsoCh = correctedPfIsoCharged03(pid_pfIsoCharged03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    float corrIsoNe = correctedPfIsoNeutrals03(pid_pfIsoNeutrals03ForCiC_presel[recoP], etascPhot_presel[recoP]);
    float corrIsoPh = correctedPfIsoPhotons03(pid_pfIsoPhotons03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    if (isBarrel) {
      if ( corrIsoCh > 1.5) continue;
      if ( corrIsoNe > 1.0 + 0.04*ptPhot_presel[recoP])  continue;
      if ( corrIsoPh > 0.7 + 0.005*ptPhot_presel[recoP]) continue;
    } else {
      if ( corrIsoCh > 1.2) continue;
      if ( corrIsoNe > 1.5 + 0.04*ptPhot_presel[recoP])  continue;
      if ( corrIsoPh > 1.0 + 0.005*ptPhot_presel[recoP]) continue;
    }
    
    selPhotons.push_back(photons[ipho]);
  }
  return selPhotons;
}

std::vector<int> upgradeFakeAnalysis::selectedPhotonsTight(const std::vector<int>& photons) {

  std::vector<int> selPhotons;
  
  for (int ipho=0;ipho<(int)photons.size();++ipho) {

    int recoP = photons[ipho];
    
    // EB/EE
    bool isBarrel = false;
    float etaSc = etascPhot_presel[recoP];
    if (fabs(etaSc)<1.5) isBarrel=true;
    
    // electron veto
    if ( !val_pho_isconv_presel[recoP] ) continue;
    
    // identification
    if ( isBarrel ) {  
      if ( pid_HoverE_presel[recoP]>0.05 )   continue;
      if ( sEtaEtaPhot_presel[recoP]>0.011 ) continue;
    } else {     
      if(pid_HoverE_presel[recoP]>0.05)    continue;
      if (sEtaEtaPhot_presel[recoP]>0.031) continue;
    }

    // isolation 
    float corrIsoCh = correctedPfIsoCharged03(pid_pfIsoCharged03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    float corrIsoNe = correctedPfIsoNeutrals03(pid_pfIsoNeutrals03ForCiC_presel[recoP], etascPhot_presel[recoP]);
    float corrIsoPh = correctedPfIsoPhotons03(pid_pfIsoPhotons03ForCiC_presel[recoP],  etascPhot_presel[recoP]);
    if (isBarrel) {
      if ( corrIsoCh > 0.7) continue;
      if ( corrIsoNe > 0.4 + 0.04*ptPhot_presel[recoP])  continue;
      if ( corrIsoPh > 0.5 + 0.005*ptPhot_presel[recoP]) continue;
    } else {
      if ( corrIsoCh > 0.5) continue;
      if ( corrIsoNe > 1.5 + 0.04*ptPhot_presel[recoP])  continue;
      if ( corrIsoPh > 1.0 + 0.005*ptPhot_presel[recoP]) continue;
    }
    
    selPhotons.push_back(photons[ipho]);
  }
  return selPhotons;
}

// chiara: ma e' ok cosi'? anche x g+jet...
float upgradeFakeAnalysis::combinedPfIso03(float isoCharged03, float isoNeutral03, float isoPhoton03, float eta) {
  
  float EA_charged[7] = { 0.012, 0.010, 0.014, 0.012, 0.016, 0.020, 0.012};
  float EA_neutral[7] = { 0.030, 0.057, 0.039, 0.015, 0.024, 0.039, 0.072};
  float EA_photons[7] = { 0.148, 0.130, 0.112, 0.216, 0.262, 0.260, 0.266};
  
  int theEAregion_fG = effectiveAreaRegion(eta);
  float combIso =  isoCharged03 - rhoAllJets*EA_charged[theEAregion_fG] + isoNeutral03 - rhoAllJets*EA_neutral[theEAregion_fG]  + isoPhoton03 - rhoAllJets*EA_photons[theEAregion_fG];
  if (combIso<=0) combIso = 0;

  return combIso;
}

float upgradeFakeAnalysis::correctedPfIsoCharged03(float isoCharged03, float eta) {
  
  float EA_charged[7] = { 0.012, 0.010, 0.014, 0.012, 0.016, 0.020, 0.012};
  int theEAregion_fG  = effectiveAreaRegion(eta);    
  float corrIso = isoCharged03 - rhoAllJets*EA_charged[theEAregion_fG];
  if (corrIso<=0) corrIso = 0;
  
  return corrIso;
}

float upgradeFakeAnalysis::correctedPfIsoNeutrals03(float isoNeutrals03, float eta) {

  float EA_neutral[7] = { 0.030, 0.057, 0.039, 0.015, 0.024, 0.039, 0.072};
  int theEAregion_fG  = effectiveAreaRegion(eta);       
  float corrIso = isoNeutrals03 - rhoAllJets*EA_neutral[theEAregion_fG];
  if (corrIso<=0) corrIso = 0;

  return corrIso;
}

float upgradeFakeAnalysis::correctedPfIsoPhotons03(float isoPhotons03, float eta) {
  
  float EA_photons[7] = { 0.148, 0.130, 0.112, 0.216, 0.262, 0.260, 0.266};
  int theEAregion_fG  = effectiveAreaRegion(eta);      
  float corrIso = isoPhotons03 - rhoAllJets*EA_photons[theEAregion_fG];
  if (corrIso<=0) corrIso = 0;

  return corrIso;
}

std::vector<int> upgradeFakeAnalysis::sortedPtPhotons() {

  std::vector<int> sortedPhotons;
  int sorted_index[nPhot_presel];
  TMath::Sort(nPhot_presel,ptPhot_presel,sorted_index);
  for (int ipho=0;ipho<nPhot_presel;++ipho)
    sortedPhotons.push_back(sorted_index[ipho]);
  return sortedPhotons;
}

std::vector<int> upgradeFakeAnalysis::sortedPtGenPhotons() {
  
  std::vector<int> sortedGenPhotons;
  int sorted_index[nPhot_gen];
  TMath::Sort(nPhot_gen,ptTrueMatch_gen,sorted_index);
  for (int ipho=0;ipho<nPhot_gen;++ipho)
    sortedGenPhotons.push_back(sorted_index[ipho]);
  return sortedGenPhotons;
}

void upgradeFakeAnalysis::BookHistos(){ 

  H_vtx = new TH1F("H_vtx","H_vtx",100,0,100);

  H_matchedEB_convSafe = new TH1F("H_matchedEB_convSafe","H_matchedEB_convSafe",2, 0, 2);
  H_matchedEB_HoE      = new TH1F("H_matchedEB_HoE","H_matchedEB_HoE",120,0,0.5);
  H_matchedEB_sIeIe    = new TH1F("H_matchedEB_sIeIe","H_matchedEB_sIeIe",120,0.,0.03);      
  H_matchedEB_uncIsoCh = new TH1F("H_matchedEB_uncIsoCh","H_matchedEB_uncIsoCh",120,0.,30.);
  H_matchedEB_uncIsoNe = new TH1F("H_matchedEB_uncIsoNe","H_matchedEB_uncIsoNe",120,0.,30.);
  H_matchedEB_uncIsoPh = new TH1F("H_matchedEB_uncIsoPh","H_matchedEB_uncIsoPh",120,0.,30.);
  H_matchedEB_corIsoCh = new TH1F("H_matchedEB_corIsoCh","H_matchedEB_corIsoCh",120,0.,30.);
  H_matchedEB_corIsoNe = new TH1F("H_matchedEB_corIsoNe","H_matchedEB_corIsoNe",120,0.,30.);
  H_matchedEB_corIsoPh = new TH1F("H_matchedEB_corIsoPh","H_matchedEB_corIsoPh",120,0.,30.);
  P_matchedEB_uncIsoChVsNvtx = new TProfile("P_matchedEB_uncIsoChVsNvtx","P_matchedEB_uncIsoChVsNvtx",79,1.,80);
  P_matchedEB_uncIsoNeVsNvtx = new TProfile("P_matchedEB_uncIsoNeVsNvtx","P_matchedEB_uncIsoNeVsNvtx",79,1.,80);
  P_matchedEB_uncIsoPhVsNvtx = new TProfile("P_matchedEB_uncIsoPhVsNvtx","P_matchedEB_uncIsoPhVsNvtx",79,1.,80);
  P_matchedEB_corIsoChVsNvtx = new TProfile("P_matchedEB_corIsoChVsNvtx","P_matchedEB_corIsoChVsNvtx",79,1.,80);
  P_matchedEB_corIsoNeVsNvtx = new TProfile("P_matchedEB_corIsoNeVsNvtx","P_matchedEB_corIsoNeVsNvtx",79,1.,80);
  P_matchedEB_corIsoPhVsNvtx = new TProfile("P_matchedEB_corIsoPhVsNvtx","P_matchedEB_corIsoPhVsNvtx",79,1.,80);

  H_matchedEE_convSafe = new TH1F("H_matchedEE_convSafe","H_matchedEE_convSafe",2, 0, 2);
  H_matchedEE_HoE      = new TH1F("H_matchedEE_HoE","H_matchedEE_HoE",120,0,0.5);
  H_matchedEE_sIeIe    = new TH1F("H_matchedEE_sIeIe","H_matchedEE_sIeIe",120,0.,0.06);      
  H_matchedEE_uncIsoCh = new TH1F("H_matchedEE_uncIsoCh","H_matchedEE_uncIsoCh",120,0.,30.);
  H_matchedEE_uncIsoNe = new TH1F("H_matchedEE_uncIsoNe","H_matchedEE_uncIsoNe",120,0.,30.);
  H_matchedEE_uncIsoPh = new TH1F("H_matchedEE_uncIsoPh","H_matchedEE_uncIsoPh",120,0.,30.);
  H_matchedEE_corIsoCh = new TH1F("H_matchedEE_corIsoCh","H_matchedEE_corIsoCh",120,0.,30.);
  H_matchedEE_corIsoNe = new TH1F("H_matchedEE_corIsoNe","H_matchedEE_corIsoNe",120,0.,30.);
  H_matchedEE_corIsoPh = new TH1F("H_matchedEE_corIsoPh","H_matchedEE_corIsoPh",120,0.,30.);
  P_matchedEE_uncIsoChVsNvtx = new TProfile("P_matchedEE_uncIsoChVsNvtx","P_matchedEE_uncIsoChVsNvtx",79,1.,80);
  P_matchedEE_uncIsoNeVsNvtx = new TProfile("P_matchedEE_uncIsoNeVsNvtx","P_matchedEE_uncIsoNeVsNvtx",79,1.,80);
  P_matchedEE_uncIsoPhVsNvtx = new TProfile("P_matchedEE_uncIsoPhVsNvtx","P_matchedEE_uncIsoPhVsNvtx",79,1.,80);
  P_matchedEE_corIsoChVsNvtx = new TProfile("P_matchedEE_corIsoChVsNvtx","P_matchedEE_corIsoChVsNvtx",79,1.,80);
  P_matchedEE_corIsoNeVsNvtx = new TProfile("P_matchedEE_corIsoNeVsNvtx","P_matchedEE_corIsoNeVsNvtx",79,1.,80);
  P_matchedEE_corIsoPhVsNvtx = new TProfile("P_matchedEE_corIsoPhVsNvtx","P_matchedEE_corIsoPhVsNvtx",79,1.,80);

  H_unmatchedEB_convSafe = new TH1F("H_unmatchedEB_convSafe","H_unmatchedEB_convSafe",2, 0, 2);
  H_unmatchedEB_HoE      = new TH1F("H_unmatchedEB_HoE","H_unmatchedEB_HoE",120,0,0.5);
  H_unmatchedEB_sIeIe    = new TH1F("H_unmatchedEB_sIeIe","H_unmatchedEB_sIeIe",120,0.,0.03);      
  H_unmatchedEB_uncIsoCh = new TH1F("H_unmatchedEB_uncIsoCh","H_unmatchedEB_uncIsoCh",120,0.,30.);
  H_unmatchedEB_uncIsoNe = new TH1F("H_unmatchedEB_uncIsoNe","H_unmatchedEB_uncIsoNe",120,0.,30.);
  H_unmatchedEB_uncIsoPh = new TH1F("H_unmatchedEB_uncIsoPh","H_unmatchedEB_uncIsoPh",120,0.,30.);
  H_unmatchedEB_corIsoCh = new TH1F("H_unmatchedEB_corIsoCh","H_unmatchedEB_corIsoCh",120,0.,30.);
  H_unmatchedEB_corIsoNe = new TH1F("H_unmatchedEB_corIsoNe","H_unmatchedEB_corIsoNe",120,0.,30.);
  H_unmatchedEB_corIsoPh = new TH1F("H_unmatchedEB_corIsoPh","H_unmatchedEB_corIsoPh",120,0.,30.);

  H_unmatchedEE_convSafe = new TH1F("H_unmatchedEE_convSafe","H_unmatchedEE_convSafe",2, 0, 2);
  H_unmatchedEE_HoE      = new TH1F("H_unmatchedEE_HoE","H_unmatchedEE_HoE",120,0,0.5);
  H_unmatchedEE_sIeIe    = new TH1F("H_unmatchedEE_sIeIe","H_unmatchedEE_sIeIe",120,0.,0.06);      
  H_unmatchedEE_uncIsoCh = new TH1F("H_unmatchedEE_uncIsoCh","H_unmatchedEE_uncIsoCh",120,0.,30.);
  H_unmatchedEE_uncIsoNe = new TH1F("H_unmatchedEE_uncIsoNe","H_unmatchedEE_uncIsoNe",120,0.,30.);
  H_unmatchedEE_uncIsoPh = new TH1F("H_unmatchedEE_uncIsoPh","H_unmatchedEE_uncIsoPh",120,0.,30.);
  H_unmatchedEE_corIsoCh = new TH1F("H_unmatchedEE_corIsoCh","H_unmatchedEE_corIsoCh",120,0.,30.);
  H_unmatchedEE_corIsoNe = new TH1F("H_unmatchedEE_corIsoNe","H_unmatchedEE_corIsoNe",120,0.,30.);
  H_unmatchedEE_corIsoPh = new TH1F("H_unmatchedEE_corIsoPh","H_unmatchedEE_corIsoPh",120,0.,30.);
}

void upgradeFakeAnalysis::SaveHistos(){ 

  TFile myOutput("myOutFile.root","RECREATE");
  myOutput.cd();
  
  H_vtx->Write();

  H_matchedEB_convSafe -> Write();
  H_matchedEB_HoE      -> Write(); 
  H_matchedEB_sIeIe    -> Write();
  H_matchedEB_uncIsoCh -> Write();
  H_matchedEB_uncIsoNe -> Write();
  H_matchedEB_uncIsoPh -> Write();
  H_matchedEB_corIsoCh -> Write();
  H_matchedEB_corIsoNe -> Write();
  H_matchedEB_corIsoPh -> Write();
  P_matchedEB_uncIsoChVsNvtx -> Write();
  P_matchedEB_uncIsoNeVsNvtx -> Write();
  P_matchedEB_uncIsoPhVsNvtx -> Write();
  P_matchedEB_corIsoChVsNvtx -> Write();
  P_matchedEB_corIsoNeVsNvtx -> Write();
  P_matchedEB_corIsoPhVsNvtx -> Write();

  H_matchedEE_convSafe -> Write();
  H_matchedEE_HoE      -> Write(); 
  H_matchedEE_sIeIe    -> Write();
  H_matchedEE_uncIsoCh -> Write();
  H_matchedEE_uncIsoNe -> Write();
  H_matchedEE_uncIsoPh -> Write();
  H_matchedEE_corIsoCh -> Write();
  H_matchedEE_corIsoNe -> Write();
  H_matchedEE_corIsoPh -> Write();
  P_matchedEE_uncIsoChVsNvtx -> Write();
  P_matchedEE_uncIsoNeVsNvtx -> Write();
  P_matchedEE_uncIsoPhVsNvtx -> Write();
  P_matchedEE_corIsoChVsNvtx -> Write();
  P_matchedEE_corIsoNeVsNvtx -> Write();
  P_matchedEE_corIsoPhVsNvtx -> Write();

  H_unmatchedEB_convSafe -> Write();
  H_unmatchedEB_HoE      -> Write(); 
  H_unmatchedEB_sIeIe    -> Write();
  H_unmatchedEB_uncIsoCh -> Write();
  H_unmatchedEB_uncIsoNe -> Write();
  H_unmatchedEB_uncIsoPh -> Write();
  H_unmatchedEB_corIsoCh -> Write();
  H_unmatchedEB_corIsoNe -> Write();
  H_unmatchedEB_corIsoPh -> Write();

  H_unmatchedEE_convSafe -> Write();
  H_unmatchedEE_HoE      -> Write(); 
  H_unmatchedEE_sIeIe    -> Write();
  H_unmatchedEE_uncIsoCh -> Write();
  H_unmatchedEE_uncIsoNe -> Write();
  H_unmatchedEE_uncIsoPh -> Write();
  H_unmatchedEE_corIsoCh -> Write();
  H_unmatchedEE_corIsoNe -> Write();
  H_unmatchedEE_corIsoPh -> Write();

  std::cout << "Written output into myOutFile.root" << std::endl;
  myOutput.Close();
}

