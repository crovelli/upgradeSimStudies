//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 12 10:38:25 2014 by ROOT version 5.34/03
// from TTree tree_reader_up/Analysis tree
// found on file: dcap://cmsrm-se01.roma1.infn.it/pnfs/roma1.infn.it/data/cms/store/user/crovelli/ProdUpgrade2014/GJet_Pt40_UpgradePhase1Age0DES_DR61SLHCx_NoPileUp/output_1_2_xKR.root
//////////////////////////////////////////////////////////

#ifndef tree_reader_up_h
#define tree_reader_up_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>

using namespace std;

class tree_reader_up {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         genpt;
   Int_t           genProcessId;
   Float_t         genQScale;
   Bool_t          isMC;
   Bool_t          passEcalLaserFilter;
   Bool_t          passHBHENoiseFilter;
   Bool_t          passCSCTightHaloFilter;
   Bool_t          passhcalLaserEventFilter;
   Bool_t          passEcalDeadCellTriggerPrimitiveFilter;
   Bool_t          passtrackingFailureFilter;
   Bool_t          passeeBadScFilter;
   Int_t           store;
   Int_t           lbn;
   Int_t           bx;
   Int_t           orbit;
   Int_t           run;
   Int_t           event;
   Float_t         rhoPF;
   Float_t         rhoCalo;
   Float_t         rhoAllJets;
   Int_t           nMC;
   Int_t           pdgIdMC[200];   //[nMC]
   Int_t           statusMC[200];   //[nMC]
   Int_t           motherIDMC[200];   //[nMC]
   Float_t         ptMC [200];   //[nMC]
   Float_t         eMC  [200];   //[nMC]
   Float_t         etaMC[200];   //[nMC]
   Float_t         phiMC[200];   //[nMC]
   Int_t           pu_n;
   Int_t           pu_true_n;
   Float_t         pu_zpos[100];   //[pu_n]
   Float_t         pu_sumpt_lowpt[100];   //[pu_n]
   Float_t         pu_sumpt_highpt[100];   //[pu_n]
   Float_t         pu_ntrks_lowpt[100];   //[pu_n]
   Float_t         pu_ntrks_highpt[100];   //[pu_n]
   Int_t           nPhot;
   Float_t         ptPhot [50];   //[nPhot]
   Float_t         ePhot  [50];   //[nPhot]
   Float_t         escPhot  [50];   //[nPhot]
   Float_t         escRegrPhot  [50];   //[nPhot]
   Float_t         escRegrPhotError  [50];   //[nPhot]
   Float_t         escPhFixPhot  [50];   //[nPhot]
   Float_t         escPhFixPhotError  [50];   //[nPhot]
   Float_t         escRawPhot  [50];   //[nPhot]
   Float_t         etascPhot  [50];   //[nPhot]
   Float_t         phiscPhot  [50];   //[nPhot]
   Float_t         xscPhot  [50];   //[nPhot]
   Float_t         yscPhot  [50];   //[nPhot]
   Float_t         zscPhot  [50];   //[nPhot]
   Float_t         xcaloPhot  [50];   //[nPhot]
   Float_t         ycaloPhot  [50];   //[nPhot]
   Float_t         zcaloPhot  [50];   //[nPhot]
   Float_t         eseedPhot  [50];   //[nPhot]
   Float_t         etaPhot[50];   //[nPhot]
   Float_t         phiPhot[50];   //[nPhot]
   Float_t         timePhot[50];   //[nPhot]
   Float_t         e4SwissCrossPhot[50];   //[nPhot]
   Int_t           hasPixelSeedPhot[50];   //[nPhot]
   Int_t           hasMatchedPromptElePhot[50];   //[nPhot]
   Int_t           hasMatchedConvPhot[50];   //[nPhot]
   Bool_t          isEBPhot[50];   //[nPhot]
   Bool_t          isEEPhot[50];   //[nPhot]
   Bool_t          isEBEEGapPhot[50];   //[nPhot]
   Int_t           ntracksConvPhot[50];   //[nPhot]
   Bool_t          isValidVtxConvPhot[50];   //[nPhot]
   Float_t         pairInvmassConvPhot[50];   //[nPhot]
   Float_t         pairCotThetaSeperationConvPhot[50];   //[nPhot]
   Float_t         pairmomentumXConvPhot[50];   //[nPhot]
   Float_t         pairmomentumYConvPhot[50];   //[nPhot]
   Float_t         pairmomentumZConvPhot[50];   //[nPhot]
   Float_t         chi2ConvPhot[50];   //[nPhot]
   Float_t         nDofConvPhot[50];   //[nPhot]
   Float_t         eOverPConvPhot[50];   //[nPhot]
   Float_t         convVxConvPhot[50];   //[nPhot]
   Float_t         convVyConvPhot[50];   //[nPhot]
   Float_t         convVzConvPhot[50];   //[nPhot]
   Float_t         distOfMinimumApproachConvPhot[50];   //[nPhot]
   Float_t         dPhiTracksAtVtxConvPhot[50];   //[nPhot]
   Bool_t          pid_isEM[50];   //[nPhot]
   Bool_t          pid_isLoose[50];   //[nPhot]
   Bool_t          pid_isTight[50];   //[nPhot]
   Float_t         pid_jurECAL[50];   //[nPhot]
   Float_t         pid_twrHCAL[50];   //[nPhot]
   Float_t         pid_HoverE[50];   //[nPhot]
   Float_t         pid_hlwTrack[50];   //[nPhot]
   Float_t         pid_hlwTrackNoDz[50];   //[nPhot]
   Float_t         pid_hlwTrackForCiC[40][100];
   Float_t         pid_etawid[50];   //[nPhot]
   Float_t         pid_jurECAL03[50];   //[nPhot]
   Float_t         pid_twrHCAL03[50];   //[nPhot]
   Float_t         pid_hlwTrack03[50];   //[nPhot]
   Float_t         pid_hlwTrack03NoDz[50];   //[nPhot]
   Float_t         pid_hlwTrack03ForCiC[50][100];
   Float_t         pid_pfIsoCharged01ForCiC[50][100];
   Float_t         pid_pfIsoCharged02ForCiC[50][100];
   Float_t         pid_pfIsoCharged03ForCiC[50][100];
   Float_t         pid_pfIsoCharged04ForCiC[50][100];
   Float_t         pid_pfIsoCharged05ForCiC[50][100];
   Float_t         pid_pfIsoCharged06ForCiC[50][100];
   Float_t         pid_pfIsoPhotons01ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoPhotons02ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoPhotons03ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoPhotons04ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoPhotons05ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoPhotons06ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals01ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals02ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals03ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals04ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals05ForCiC[50];   //[nPhot]
   Float_t         pid_pfIsoNeutrals06ForCiC[50];   //[nPhot]
   Float_t         ptiso004Phot[50];   //[nPhot]
   Int_t           ntrkiso004Phot[50];   //[nPhot]
   Float_t         ptiso035Phot[50];   //[nPhot]
   Int_t           ntrkiso035Phot[50];   //[nPhot]
   Float_t         ptiso04Phot[50];   //[nPhot]
   Int_t           ntrkiso04Phot[50];   //[nPhot]
   Float_t         hcalovecal04Phot[50];   //[nPhot]
   Float_t         ecaliso04Phot[50];   //[nPhot]
   Float_t         pid_scetawid[50];   //[nPhot]
   Float_t         pid_scphiwid[50];   //[nPhot]
   Float_t         pid_lambdaRatio[50];   //[nPhot]
   Float_t         pid_esXwidth[50];   //[nPhot]
   Float_t         pid_esYwidth[50];   //[nPhot]
   Float_t         sMajMajPhot[50];   //[nPhot]
   Float_t         sMinMinPhot[50];   //[nPhot]
   Float_t         alphaPhot[50];   //[nPhot]
   Float_t         sEtaEtaPhot[50];   //[nPhot]
   Float_t         sEtaPhiPhot[50];   //[nPhot]
   Float_t         sPhiPhiPhot[50];   //[nPhot]
   Float_t         E1Phot[50];   //[nPhot]
   Float_t         E2OverE9Phot[50];   //[nPhot]
   Float_t         E4Phot[50];   //[nPhot]
   Float_t         E9Phot[50];   //[nPhot]
   Float_t         E25Phot[50];   //[nPhot]
   Int_t           ieleassocPhot[50];   //[nPhot]
   Float_t         pid_deltaRToTrackPhot[50];   //[nPhot]
   Int_t           nElePhot;
   Float_t         pid_jurECALElePhot [50];   //[nElePhot]
   Float_t         pid_twrHCALElePhot [50];   //[nElePhot]
   Float_t         pid_HoverEElePhot [50];   //[nElePhot]
   Float_t         pid_hlwTrackElePhot [50];   //[nElePhot]
   Float_t         pid_etawidElePhot [50];   //[nElePhot]
   Float_t         pid_dphivtxElePhot [50];   //[nElePhot]
   Float_t         pid_detavtxElePhot [50];   //[nElePhot]
   Int_t           pid_mishitsElePhot [50];   //[nElePhot]
   Float_t         pid_distElePhot [50];   //[nElePhot]
   Float_t         pid_dcotElePhot [50];   //[nElePhot]
   Float_t         pid_ptElePhot [50];   //[nElePhot]
   Int_t           nJet_pfakt5;
   Float_t         ptJet_pfakt5 [200];   //[nJet_pfakt5]
   Float_t         ptCorrJet_pfakt5 [200];   //[nJet_pfakt5]
   Float_t         eJet_pfakt5  [200];   //[nJet_pfakt5]
   Float_t         etaJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptDJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         rmsCandJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         rmsCandTrueJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         axis1Jet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         axis2Jet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pullJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         tanaJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptD_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         rmsCandTrue_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         axis1_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         axis2_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pull_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         tana_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         RchgJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         RneutralJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         RJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         Rchg_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nChg_ptCutJet_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nChg_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nChg_ptCut_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nNeutral_ptCutJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pTMaxJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pTMaxChgJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pTMaxNeutralJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         pTMaxChg_QCJet_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_dRMean_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_frac01_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_frac02_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_frac03_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_frac04_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_frac05_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_nNeutrals_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_beta_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_betaStar_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_dZ_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_nCharged_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_dR2Mean_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetId_betaStarClassic_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetIdSimple_mva_pfakt5[200];   //[nJet_pfakt5]
   Int_t           jetIdSimple_wp_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetIdFull_mva_pfakt5[200];   //[nJet_pfakt5]
   Int_t           jetIdFull_wp_pfakt5[200];   //[nJet_pfakt5]
   Float_t         jetIdCutBased_mva_pfakt5[200];   //[nJet_pfakt5]
   Int_t           jetIdCutBased_wp_pfakt5[200];   //[nJet_pfakt5]
   Float_t         beta_pfakt5[100][100];
   Float_t         betaStar_pfakt5[100][100];
   Float_t         combinedSecondaryVertexBJetTags[200];   //[nJet_pfakt5]
   Float_t         combinedSecondaryVertexMVABJetTags[200];   //[nJet_pfakt5]
   Float_t         jetBProbabilityBJetTags[200];   //[nJet_pfakt5]
   Float_t         jetProbabilityBJetTags[200];   //[nJet_pfakt5]
   Float_t         simpleSecondaryVertexHighEffBJetTags[200];   //[nJet_pfakt5]
   Float_t         simpleSecondaryVertexHighPurBJetTags[200];   //[nJet_pfakt5]
   Float_t         softMuonBJetTags[200];   //[nJet_pfakt5]
   Float_t         softMuonByIP3dBJetTags[200];   //[nJet_pfakt5]
   Float_t         softMuonByPtBJetTags[200];   //[nJet_pfakt5]
   Float_t         softElectronByIP3dBJetTags[200];   //[nJet_pfakt5]
   Float_t         softElectronByPtBJetTags[200];   //[nJet_pfakt5]
   Float_t         trackCountingHighPurBJetTags[200];   //[nJet_pfakt5]
   Float_t         trackCountingHighEffBJetTags[200];   //[nJet_pfakt5]
   Int_t           npfcand_all;
   Int_t           nChargedHadrons_uncl;
   Int_t           nChargedHadronsgoodvtx_uncl;
   Int_t           nChargedHadronsnoothervtx_uncl;
   Int_t           nPhotons_uncl;
   Int_t           nMuons_uncl;
   Int_t           nElectrons_uncl;
   Int_t           nNeutralHadrons_uncl;
   Int_t           nHFHadrons_uncl;
   Int_t           nHFEM_uncl;
   Float_t         epfcand_all;
   Float_t         eChargedHadrons_uncl;
   Float_t         eChargedHadronsgoodvtx_uncl;
   Float_t         eChargedHadronsnoothervtx_uncl;
   Float_t         ePhotons_uncl;
   Float_t         eMuons_uncl;
   Float_t         eElectrons_uncl;
   Float_t         eNeutralHadrons_uncl;
   Float_t         eHFHadrons_uncl;
   Float_t         eHFEM_uncl;
   Float_t         ptpfcand_all;
   Float_t         ptChargedHadrons_uncl;
   Float_t         ptChargedHadronsgoodvtx_uncl;
   Float_t         ptChargedHadronsnoothervtx_uncl;
   Float_t         ptPhotons_uncl;
   Float_t         ptMuons_uncl;
   Float_t         ptElectrons_uncl;
   Float_t         ptNeutralHadrons_uncl;
   Float_t         ptHFHadrons_uncl;
   Float_t         ptHFEM_uncl;
   Float_t         etaChargedHadrons_uncl;
   Float_t         etaChargedHadronsgoodvtx_uncl;
   Float_t         etaChargedHadronsnoothervtx_uncl;
   Float_t         etaPhotons_uncl;
   Float_t         etaMuons_uncl;
   Float_t         etaElectrons_uncl;
   Float_t         etaNeutralHadrons_uncl;
   Float_t         etaHFHadrons_uncl;
   Float_t         etaHFEM_uncl;
   Float_t         phiChargedHadrons_uncl;
   Float_t         phiChargedHadronsgoodvtx_uncl;
   Float_t         phiChargedHadronsnoothervtx_uncl;
   Float_t         phiPhotons_uncl;
   Float_t         phiMuons_uncl;
   Float_t         phiElectrons_uncl;
   Float_t         phiNeutralHadrons_uncl;
   Float_t         phiHFHadrons_uncl;
   Float_t         phiHFEM_uncl;
   Float_t         sumptpfcand_all;
   Float_t         sumptChargedHadrons_uncl;
   Float_t         sumptChargedHadronsgoodvtx_uncl;
   Float_t         sumptChargedHadronsnoothervtx_uncl;
   Float_t         sumptPhotons_uncl;
   Float_t         sumptMuons_uncl;
   Float_t         sumptElectrons_uncl;
   Float_t         sumptNeutralHadrons_uncl;
   Float_t         sumptHFHadrons_uncl;
   Float_t         sumptHFEM_uncl;
   Int_t           nChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nPhotons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nMuons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nElectrons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nHFEM_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ePhotons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eMuons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eElectrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         eHFEM_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptPhotons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptMuons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptElectrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         ptHFEM_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaPhotons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaMuons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaElectrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         etaHFEM_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiPhotons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiMuons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiElectrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         phiHFEM_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptChargedHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptChargedHadronsgoodvtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptChargedHadronsnoothervtx_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptPhotons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptMuons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptElectrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptNeutralHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptHFHadrons_pfakt5[200];   //[nJet_pfakt5]
   Float_t         sumptHFEM_pfakt5[200];   //[nJet_pfakt5]
   Int_t           nJet_pfakt7;
   Float_t         ptJet_pfakt7 [200];   //[nJet_pfakt7]
   Float_t         ptCorrJet_pfakt7 [200];   //[nJet_pfakt7]
   Float_t         eJet_pfakt7  [200];   //[nJet_pfakt7]
   Float_t         etaJet_pfakt7[200];   //[nJet_pfakt7]
   Float_t         phiJet_pfakt7[200];   //[nJet_pfakt7]
   Int_t           nJetGen_akt5;
   Float_t         ptJetGen_akt5 [200];   //[nJetGen_akt5]
   Float_t         eJetGen_akt5  [200];   //[nJetGen_akt5]
   Float_t         etaJetGen_akt5[200];   //[nJetGen_akt5]
   Float_t         phiJetGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nMuonsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nElectronsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nPhotonsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nTracksGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nNeutralHadronsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nHFHadronsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nHFEMGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nNeutronsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nK0LGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nK0SGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nLambdasGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nCsiGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nOtherNeutralHadronsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eMuonsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eElectronsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         ePhotonsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eTracksGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eNeutralHadronsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eHFHadronsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eHFEMGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eNeutronsGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eK0LGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eK0SGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eLambdasGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eCsiGen_akt5[200];   //[nJetGen_akt5]
   Float_t         eOtherNeutralHadronsGen_akt5[200];   //[nJetGen_akt5]
   Int_t           nJetGen_akt7;
   Float_t         ptJetGen_akt7 [200];   //[nJetGen_akt7]
   Float_t         eJetGen_akt7  [200];   //[nJetGen_akt7]
   Float_t         etaJetGen_akt7[200];   //[nJetGen_akt7]
   Float_t         phiJetGen_akt7[200];   //[nJetGen_akt7]
   Int_t           nvertex;
   Float_t         sMet  ;
   Float_t         eMet  ;
   Float_t         phiMet;
   Float_t         signifMet;
   Float_t         sCorrMet  ;
   Float_t         eCorrMet  ;
   Float_t         phiCorrMet;
   Float_t         signifCorrMet;
   Float_t         sNoHFMet  ;
   Float_t         eNoHFMet  ;
   Float_t         phiNoHFMet;
   Float_t         signifNoHFMet;
   Float_t         stcMet;
   Float_t         etcMet;
   Float_t         phitcMet;
   Float_t         signiftcMet;
   Float_t         sglobalPfMet;
   Float_t         eglobalPfMet;
   Float_t         phiglobalPfMet;
   Float_t         signifglobalPfMet;
   Float_t         scentralPfMet;
   Float_t         ecentralPfMet;
   Float_t         phicentralPfMet;
   Float_t         signifcentralPfMet;
   Float_t         eassocPfMet[100];   //[nvertex]
   Float_t         phiassocPfMet[100];   //[nvertex]
   Float_t         signifassocPfMet[100];   //[nvertex]
   Float_t         eassocOtherVtxPfMet[100];   //[nvertex]
   Float_t         phiassocOtherVtxPfMet[100];   //[nvertex]
   Float_t         signifassocOtherVtxPfMet[100];   //[nvertex]
   Float_t         etrkPfMet[100];   //[nvertex]
   Float_t         phitrkPfMet[100];   //[nvertex]
   Float_t         signiftrkPfMet[100];   //[nvertex]
   Float_t         ecleanPfMet[100];   //[nvertex]
   Float_t         phicleanPfMet[100];   //[nvertex]
   Float_t         signifcleanPfMet[100];   //[nvertex]
   Float_t         globalPfSums[200];
   Float_t         spfMet;
   Float_t         epfMet;
   Float_t         phipfMet;
   Float_t         signifpfMet;
   Float_t         spfMetType1;
   Float_t         epfMetType1;
   Float_t         phipfMetType1;
   Float_t         signifpfMetType1;
   Float_t         sMetGen;
   Float_t         eMetGen;
   Float_t         phiMetGen;
   Float_t         signifMetGen;
   Float_t         sMetGen2;
   Float_t         eMetGen2;
   Float_t         phiMetGen2;
   Float_t         vxMC;
   Float_t         vyMC;
   Float_t         vzMC;
   Float_t         vx[100];   //[nvertex]
   Float_t         vy[100];   //[nvertex]
   Float_t         vz[100];   //[nvertex]
   Float_t         vntracks[100];   //[nvertex]
   Float_t         vchi2[100];   //[nvertex]
   Float_t         vndof[100];   //[nvertex]
   Float_t         vlogsumpt2[100];   //[nvertex]
   Int_t           nPreselPhotonPairs;
   Int_t           indexPreselPhot1[100];   //[nPreselPhotonPairs]
   Int_t           indexPreselPhot2[100];   //[nPreselPhotonPairs]
   Int_t           vrankPhotonPairs[100];   //[nPreselPhotonPairs]
   Float_t         vevtMvaPhotonPairs[100];   //[nPreselPhotonPairs]
   Float_t         vevtProbPhotonPairs[100];   //[nPreselPhotonPairs]
   Float_t         vptbalPhotonPairs[100];   //[nPreselPhotonPairs]
   Float_t         vptasymPhotonPairs[100];   //[nPreselPhotonPairs]
   Int_t           nHLT;
   Int_t           hltNamesLen;
   vector<string>  *HLTNames;
   vector<bool>    *HLTResults;
   Int_t           nEle;
   Float_t         electron_px[100];   //[nEle]
   Float_t         electron_py[100];   //[nEle]
   Float_t         electron_pz[100];   //[nEle]
   Float_t         electron_vx[100];   //[nEle]
   Float_t         electron_vy[100];   //[nEle]
   Float_t         electron_vz[100];   //[nEle]
   Float_t         electron_pt[100];   //[nEle]
   Float_t         electron_eta[100];   //[nEle]
   Float_t         electron_phi[100];   //[nEle]
   Float_t         electron_energy[100];   //[nEle]
   Float_t         electron_ecalEnergy[100];   //[nEle]
   Float_t         electron_trackPatVtx[100];   //[nEle]
   Float_t         electron_charge[100];   //[nEle]
   Float_t         electron_fBrem[100];   //[nEle]
   Float_t         electron_dist[100];   //[nEle]
   Float_t         electron_dcot[100];   //[nEle]
   Int_t           electron_misHits[100];   //[nEle]
   Int_t           electron_matchedConv[100];   //[nEle]
   Int_t           electron_seedType[100];   //[nEle]
   Float_t         electron_EoP[100];   //[nEle]
   Float_t         electron_OneOverEMinusOneOverP[100];   //[nEle]
   Float_t         electron_r9[100];   //[nEle]
   Int_t           electron_nSubClusters[100];   //[nEle]
   Float_t         electron_trkIso[100];   //[nEle]
   Float_t         electron_ecalIso[100];   //[nEle]
   Float_t         electron_hcalIso[100];   //[nEle]
   Float_t         electron_trkIso03[100];   //[nEle]
   Float_t         electron_ecalIso03[100];   //[nEle]
   Float_t         electron_hcalIso03[100];   //[nEle]
   Float_t         electron_SigmaIetaIeta[100];   //[nEle]
   Float_t         electron_SigmaIphiIphi[100];   //[nEle]
   Float_t         electron_dEtaIn[100];   //[nEle]
   Float_t         electron_dPhiIn[100];   //[nEle]
   Float_t         electron_HoE[100];   //[nEle]
   Float_t         electron_pFlowMVA[100];   //[nEle]
   Float_t         electron_sc_energy[100];   //[nEle]
   Float_t         electron_sc_eta[100];   //[nEle]
   Float_t         electron_sc_phi[100];   //[nEle]
   Float_t         electron_mvaNonTrig[100];   //[nEle]
   Float_t         electron_mvaTrig[100];   //[nEle]
   Float_t         electron_chHad03Iso[100];   //[nEle]
   Float_t         electron_nHad03Iso[100];   //[nEle]
   Float_t         electron_phot03Iso[100];   //[nEle]
   Float_t         electron_chHad04Iso[100];   //[nEle]
   Float_t         electron_nHad04Iso[100];   //[nEle]
   Float_t         electron_phot04Iso[100];   //[nEle]
   Float_t         electron_chHad05Iso[100];   //[nEle]
   Float_t         electron_nHad05Iso[100];   //[nEle]
   Float_t         electron_phot05Iso[100];   //[nEle]
   Bool_t          isBeamHaloGlobalLoosePass;
   Bool_t          isBeamHaloGlobalTightPass;
   Bool_t          isBeamHaloHcalLoosePass;
   Bool_t          isBeamHaloHcalTightPass;
   Bool_t          isBeamHaloCSCLoosePass;
   Bool_t          isBeamHaloCSCTightPass;
   Bool_t          isBeamHaloEcalLoosePass;
   Bool_t          isBeamHaloEcalTightPass;
   Bool_t          isBeamHaloIDTightPass;
   Bool_t          isBeamHaloIDLoosePass;
   Bool_t          isSmellsLikeHalo_Tag;
   Bool_t          isLooseHalo_Tag;
   Bool_t          isTightHalo_Tag;
   Bool_t          isExtremeTightHalo_Tag;
   Int_t           nMuons;
   Float_t         Muon_px[100];   //[nMuons]
   Float_t         Muon_py[100];   //[nMuons]
   Float_t         Muon_pz[100];   //[nMuons]
   Float_t         Muon_vx[100];   //[nMuons]
   Float_t         Muon_vy[100];   //[nMuons]
   Float_t         Muon_vz[100];   //[nMuons]
   Float_t         Muon_pt[100];   //[nMuons]
   Float_t         Muon_eta[100];   //[nMuons]
   Float_t         Muon_phi[100];   //[nMuons]
   Float_t         Muon_energy[100];   //[nMuons]
   Float_t         Muon_charge[100];   //[nMuons]
   Bool_t          Muon_isGlobalMuon[100];   //[nMuons]
   Bool_t          Muon_isTrackerMuon[100];   //[nMuons]
   Bool_t          Muon_isStandAloneMuon[100];   //[nMuons]
   Int_t           Muon_trkLayerWithMeas[100];   //[nMuons]
   Bool_t          Muon_InnerTrack_isNonnull[100];   //[nMuons]
   Bool_t          Muon_OuterTrack_isNonnull[100];   //[nMuons]
   Float_t         Muon_OuterPoint_x[100];   //[nMuons]
   Float_t         Muon_OuterPoint_y[100];   //[nMuons]
   Float_t         Muon_OuterPoint_z[100];   //[nMuons]
   Bool_t          Muon_isPFMuon[100];   //[nMuons]
   Float_t         Muon_pfiso04_chHad[100];   //[nMuons]
   Float_t         Muon_pfiso04_chPar[100];   //[nMuons]
   Float_t         Muon_pfiso04_nHad[100];   //[nMuons]
   Float_t         Muon_pfiso04_Phot[100];   //[nMuons]
   Float_t         Muon_pfiso04_PUPt[100];   //[nMuons]
   Float_t         Muon_pfiso03_chHad[100];   //[nMuons]
   Float_t         Muon_pfiso03_chPar[100];   //[nMuons]
   Float_t         Muon_pfiso03_nHad[100];   //[nMuons]
   Float_t         Muon_pfiso03_Phot[100];   //[nMuons]
   Float_t         Muon_pfiso03_PUPt[100];   //[nMuons]
   Float_t         Muon_InnerPoint_x[100];   //[nMuons]
   Float_t         Muon_InnerPoint_y[100];   //[nMuons]
   Float_t         Muon_InnerPoint_z[100];   //[nMuons]
   Float_t         Muon_trackIso[100];   //[nMuons]
   Float_t         Muon_ecalIso[100];   //[nMuons]
   Float_t         Muon_hcalIso[100];   //[nMuons]
   Float_t         Muon_relIso[100];   //[nMuons]
   Int_t           Muon_normChi2[100];   //[nMuons]
   Int_t           Muon_validHits[100];   //[nMuons]
   Int_t           Muon_tkHits[100];   //[nMuons]
   Int_t           Muon_pixHits[100];   //[nMuons]
   Int_t           Muon_numberOfMatches[100];   //[nMuons]
   Int_t           nCosmicMuons;
   Float_t         CosmicMuon_px[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_py[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_pz[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_pt[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_eta[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_phi[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_energy[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_charge[100];   //[nCosmicMuons]
   Bool_t          CosmicMuon_isGlobalMuon[100];   //[nCosmicMuons]
   Bool_t          CosmicMuon_isTrackerMuon[100];   //[nCosmicMuons]
   Bool_t          CosmicMuon_isStandAloneMuon[100];   //[nCosmicMuons]
   Bool_t          CosmicMuon_InnerTrack_isNonnull[100];   //[nCosmicMuons]
   Bool_t          CosmicMuon_OuterTrack_isNonnull[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_OuterPoint_x[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_OuterPoint_y[100];   //[nCosmicMuons]
   Float_t         CosmicMuon_OuterPoint_z[100];   //[nCosmicMuons]
   Double_t        Xsec;

   // List of branches
   TBranch        *b_genpt;   //!
   TBranch        *b_genProcessId;   //!
   TBranch        *b_genQScale;   //!
   TBranch        *b_isMC;   //!
   TBranch        *b_passEcalLaserFilter;   //!
   TBranch        *b_passHBHENoiseFilter;   //!
   TBranch        *b_passCSCTightHaloFilter;   //!
   TBranch        *b_passhcalLaserEventFilter;   //!
   TBranch        *b_passEcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_passtrackingFailureFilter;   //!
   TBranch        *b_passeeBadScFilter;   //!
   TBranch        *b_store;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_orbit;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_rhoPF;   //!
   TBranch        *b_rhoCalo;   //!
   TBranch        *b_rhoAllJets;   //!
   TBranch        *b_nMC;   //!
   TBranch        *b_pdgIdMC;   //!
   TBranch        *b_statusMC;   //!
   TBranch        *b_motherIDMC;   //!
   TBranch        *b_ptMC ;   //!
   TBranch        *b_eMC  ;   //!
   TBranch        *b_etaMC;   //!
   TBranch        *b_phiMC;   //!
   TBranch        *b_pu_n;   //!
   TBranch        *b_pu_true_n;   //!
   TBranch        *b_pu_zpos;   //!
   TBranch        *b_pu_sumpt_lowpt;   //!
   TBranch        *b_pu_sumpt_highpt;   //!
   TBranch        *b_pu_ntrks_lowpt;   //!
   TBranch        *b_pu_ntrks_highpt;   //!
   TBranch        *b_nPhot;   //!
   TBranch        *b_ptPhot ;   //!
   TBranch        *b_ePhot  ;   //!
   TBranch        *b_escPhot  ;   //!
   TBranch        *b_escRegrPhot  ;   //!
   TBranch        *b_escRegrPhotError  ;   //!
   TBranch        *b_escPhFixPhot  ;   //!
   TBranch        *b_escPhFixPhotError  ;   //!
   TBranch        *b_escRawPhot  ;   //!
   TBranch        *b_etascPhot  ;   //!
   TBranch        *b_phiscPhot  ;   //!
   TBranch        *b_xscPhot  ;   //!
   TBranch        *b_yscPhot  ;   //!
   TBranch        *b_zscPhot  ;   //!
   TBranch        *b_xcaloPhot  ;   //!
   TBranch        *b_ycaloPhot  ;   //!
   TBranch        *b_zcaloPhot  ;   //!
   TBranch        *b_eseedPhot  ;   //!
   TBranch        *b_etaPhot;   //!
   TBranch        *b_phiPhot;   //!
   TBranch        *b_timePhot;   //!
   TBranch        *b_e4SwissCrossPhot;   //!
   TBranch        *b_hasPixelSeedPhot;   //!
   TBranch        *b_hasMatchedPromptElePhot;   //!
   TBranch        *b_hasMatchedConvPhot;   //!
   TBranch        *b_isEBPhot;   //!
   TBranch        *b_isEEPhot;   //!
   TBranch        *b_isEBEEGapPhot;   //!
   TBranch        *b_ntracksConvPhot;   //!
   TBranch        *b_isValidVtxConvPhot;   //!
   TBranch        *b_pairInvmassConvPhot;   //!
   TBranch        *b_pairCotThetaSeperationConvPhot;   //!
   TBranch        *b_pairmomentumXConvPhot;   //!
   TBranch        *b_pairmomentumYConvPhot;   //!
   TBranch        *b_pairmomentumZConvPhot;   //!
   TBranch        *b_chi2ConvPhot;   //!
   TBranch        *b_nDofConvPhot;   //!
   TBranch        *b_eOverPConvPhot;   //!
   TBranch        *b_convVxConvPhot;   //!
   TBranch        *b_convVyConvPhot;   //!
   TBranch        *b_convVzConvPhot;   //!
   TBranch        *b_distOfMinimumApproachConvPhot;   //!
   TBranch        *b_dPhiTracksAtVtxConvPhot;   //!
   TBranch        *b_pid_isEM;   //!
   TBranch        *b_pid_isLoose;   //!
   TBranch        *b_pid_isTight;   //!
   TBranch        *b_pid_jurECAL;   //!
   TBranch        *b_pid_twrHCAL;   //!
   TBranch        *b_pid_HoverE;   //!
   TBranch        *b_pid_hlwTrack;   //!
   TBranch        *b_pid_hlwTrackNoDz;   //!
   TBranch        *b_pid_hlwTrackBestRank;   //!
   TBranch        *b_pid_etawid;   //!
   TBranch        *b_pid_jurECAL03;   //!
   TBranch        *b_pid_twrHCAL03;   //!
   TBranch        *b_pid_hlwTrack03;   //!
   TBranch        *b_pid_hlwTrack03NoDz;   //!
   TBranch        *b_pid_hlwTrack03ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged01ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged02ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged03ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged04ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged05ForCiC;   //!
   TBranch        *b_pid_pfIsoCharged06ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons01ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons02ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons03ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons04ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons05ForCiC;   //!
   TBranch        *b_pid_pfIsoPhotons06ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals01ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals02ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals03ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals04ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals05ForCiC;   //!
   TBranch        *b_pid_pfIsoNeutrals06ForCiC;   //!
   TBranch        *b_ptiso004Phot;   //!
   TBranch        *b_ntrkiso004Phot;   //!
   TBranch        *b_ptiso035Phot;   //!
   TBranch        *b_ntrkiso035Phot;   //!
   TBranch        *b_ptiso04Phot;   //!
   TBranch        *b_ntrkiso04Phot;   //!
   TBranch        *b_hcalovecal04Phot;   //!
   TBranch        *b_ecaliso04Phot;   //!
   TBranch        *b_pid_scetawid;   //!
   TBranch        *b_pid_scphiwid;   //!
   TBranch        *b_pid_lambdaRatio;   //!
   TBranch        *b_pid_esXwidth;   //!
   TBranch        *b_pid_esYwidth;   //!
   TBranch        *b_sMajMajPhot;   //!
   TBranch        *b_sMinMinPhot;   //!
   TBranch        *b_alphaPhot;   //!
   TBranch        *b_sEtaEtaPhot;   //!
   TBranch        *b_sEtaPhiPhot;   //!
   TBranch        *b_sPhiPhiPhot;   //!
   TBranch        *b_E1Phot;   //!
   TBranch        *b_E2OverE9Phot;   //!
   TBranch        *b_E4Phot;   //!
   TBranch        *b_E9Phot;   //!
   TBranch        *b_E25Phot;   //!
   TBranch        *b_ieleassocPhot;   //!
   TBranch        *b_pid_deltaRToTrackPhot;   //!
   TBranch        *b_nElePhot;   //!
   TBranch        *b_pid_jurECALElePhot ;   //!
   TBranch        *b_pid_twrHCALElePhot ;   //!
   TBranch        *b_pid_HoverEElePhot ;   //!
   TBranch        *b_pid_hlwTrackElePhot ;   //!
   TBranch        *b_pid_etawidElePhot ;   //!
   TBranch        *b_pid_dphivtxElePhot ;   //!
   TBranch        *b_pid_detavtxElePhot ;   //!
   TBranch        *b_pid_mishitsElePhot ;   //!
   TBranch        *b_pid_distElePhot ;   //!
   TBranch        *b_pid_dcotElePhot ;   //!
   TBranch        *b_pid_ptElePhot ;   //!
   TBranch        *b_nJet_pfakt5;   //!
   TBranch        *b_ptJet_pfakt5 ;   //!
   TBranch        *b_ptCorrJet_pfakt5 ;   //!
   TBranch        *b_eJet_pfakt5  ;   //!
   TBranch        *b_etaJet_pfakt5;   //!
   TBranch        *b_phiJet_pfakt5;   //!
   TBranch        *b_ptDJet_pfakt5;   //!
   TBranch        *b_rmsCandJet_pfakt5;   //!
   TBranch        *b_rmsCandTrueJet_pfakt5;   //!
   TBranch        *b_axis1Jet_pfakt5;   //!
   TBranch        *b_axis2Jet_pfakt5;   //!
   TBranch        *b_pullJet_pfakt5;   //!
   TBranch        *b_tanaJet_pfakt5;   //!
   TBranch        *b_ptD_QCJet_pfakt5;   //!
   TBranch        *b_rmsCandTrue_QCJet_pfakt5;   //!
   TBranch        *b_axis1_QCJet_pfakt5;   //!
   TBranch        *b_axis2_QCJet_pfakt5;   //!
   TBranch        *b_pull_QCJet_pfakt5;   //!
   TBranch        *b_tana_QCJet_pfakt5;   //!
   TBranch        *b_RchgJet_pfakt5;   //!
   TBranch        *b_RneutralJet_pfakt5;   //!
   TBranch        *b_RJet_pfakt5;   //!
   TBranch        *b_Rchg_QCJet_pfakt5;   //!
   TBranch        *b_nChg_ptCutJet_pfakt5;   //!
   TBranch        *b_nChg_QCJet_pfakt5;   //!
   TBranch        *b_nChg_ptCut_QCJet_pfakt5;   //!
   TBranch        *b_nNeutral_ptCutJet_pfakt5;   //!
   TBranch        *b_pTMaxJet_pfakt5;   //!
   TBranch        *b_pTMaxChgJet_pfakt5;   //!
   TBranch        *b_pTMaxNeutralJet_pfakt5;   //!
   TBranch        *b_pTMaxChg_QCJet_pfakt5;   //!
   TBranch        *b_jetId_dRMean_pfakt5;   //!
   TBranch        *b_jetId_frac01_pfakt5;   //!
   TBranch        *b_jetId_frac02_pfakt5;   //!
   TBranch        *b_jetId_frac03_pfakt5;   //!
   TBranch        *b_jetId_frac04_pfakt5;   //!
   TBranch        *b_jetId_frac05_pfakt5;   //!
   TBranch        *b_jetId_nNeutrals_pfakt5;   //!
   TBranch        *b_jetId_beta_pfakt5;   //!
   TBranch        *b_jetId_betaStar_pfakt5;   //!
   TBranch        *b_jetId_dZ_pfakt5;   //!
   TBranch        *b_jetId_nCharged_pfakt5;   //!
   TBranch        *b_jetId_dR2Mean_pfakt5;   //!
   TBranch        *b_jetId_betaStarClassic_pfakt5;   //!
   TBranch        *b_jetIdSimple_mva_pfakt5;   //!
   TBranch        *b_jetIdSimple_wp_pfakt5;   //!
   TBranch        *b_jetIdFull_mva_pfakt5;   //!
   TBranch        *b_jetIdFull_wp_pfakt5;   //!
   TBranch        *b_jetIdCutBased_mva_pfakt5;   //!
   TBranch        *b_jetIdCutBased_wp_pfakt5;   //!
   TBranch        *b_beta_pfakt5;   //!
   TBranch        *b_betaStar_pfakt5;   //!
   TBranch        *b_combinedSecondaryVertexBJetTags;   //!
   TBranch        *b_combinedSecondaryVertexMVABJetTags;   //!
   TBranch        *b_jetBProbabilityBJetTags;   //!
   TBranch        *b_jetProbabilityBJetTags;   //!
   TBranch        *b_simpleSecondaryVertexHighEffBJetTags;   //!
   TBranch        *b_simpleSecondaryVertexHighPurBJetTags;   //!
   TBranch        *b_softMuonBJetTags;   //!
   TBranch        *b_softMuonByIP3dBJetTags;   //!
   TBranch        *b_softMuonByPtBJetTags;   //!
   TBranch        *b_softElectronByIP3dBJetTags;   //!
   TBranch        *b_softElectronByPtBJetTags;   //!
   TBranch        *b_trackCountingHighPurBJetTags;   //!
   TBranch        *b_trackCountingHighEffBJetTags;   //!
   TBranch        *b_npfcand_all;   //!
   TBranch        *b_nChargedHadrons_uncl;   //!
   TBranch        *b_nChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_nChargedHadronsothervtx_uncl;   //!
   TBranch        *b_nPhotons_uncl;   //!
   TBranch        *b_nMuons_uncl;   //!
   TBranch        *b_nElectrons_uncl;   //!
   TBranch        *b_nNeutralHadrons_uncl;   //!
   TBranch        *b_nHFHadrons_uncl;   //!
   TBranch        *b_nHFEM_uncl;   //!
   TBranch        *b_epfcand_all;   //!
   TBranch        *b_eChargedHadrons_uncl;   //!
   TBranch        *b_eChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_eChargedHadronsnoothervtx_uncl;   //!
   TBranch        *b_ePhotons_uncl;   //!
   TBranch        *b_eMuons_uncl;   //!
   TBranch        *b_eElectrons_uncl;   //!
   TBranch        *b_eNeutralHadrons_uncl;   //!
   TBranch        *b_eHFHadrons_uncl;   //!
   TBranch        *b_eHFEM_uncl;   //!
   TBranch        *b_ptpfcand_all;   //!
   TBranch        *b_ptChargedHadrons_uncl;   //!
   TBranch        *b_ptChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_ptChargedHadronsnoothervtx_uncl;   //!
   TBranch        *b_ptPhotons_uncl;   //!
   TBranch        *b_ptMuons_uncl;   //!
   TBranch        *b_ptElectrons_uncl;   //!
   TBranch        *b_ptNeutralHadrons_uncl;   //!
   TBranch        *b_ptHFHadrons_uncl;   //!
   TBranch        *b_ptHFEM_uncl;   //!
   TBranch        *b_etaChargedHadrons_uncl;   //!
   TBranch        *b_etaChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_etaChargedHadronsnoothervtx_uncl;   //!
   TBranch        *b_etaPhotons_uncl;   //!
   TBranch        *b_etaMuons_uncl;   //!
   TBranch        *b_etaElectrons_uncl;   //!
   TBranch        *b_etaNeutralHadrons_uncl;   //!
   TBranch        *b_etaHFHadrons_uncl;   //!
   TBranch        *b_etaHFEM_uncl;   //!
   TBranch        *b_phiChargedHadrons_uncl;   //!
   TBranch        *b_phiChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_phiChargedHadronsnoothervtx_uncl;   //!
   TBranch        *b_phiPhotons_uncl;   //!
   TBranch        *b_phiMuons_uncl;   //!
   TBranch        *b_phiElectrons_uncl;   //!
   TBranch        *b_phiNeutralHadrons_uncl;   //!
   TBranch        *b_phiHFHadrons_uncl;   //!
   TBranch        *b_phiHFEM_uncl;   //!
   TBranch        *b_sumptpfcand_all;   //!
   TBranch        *b_sumptChargedHadrons_uncl;   //!
   TBranch        *b_sumptChargedHadronsgoodvtx_uncl;   //!
   TBranch        *b_sumptChargedHadronsnoothervtx_uncl;   //!
   TBranch        *b_sumptPhotons_uncl;   //!
   TBranch        *b_sumptMuons_uncl;   //!
   TBranch        *b_sumptElectrons_uncl;   //!
   TBranch        *b_sumptNeutralHadrons_uncl;   //!
   TBranch        *b_sumptHFHadrons_uncl;   //!
   TBranch        *b_sumptHFEM_uncl;   //!
   TBranch        *b_nChargedHadrons_pfakt5;   //!
   TBranch        *b_nChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_nChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_nPhotons_pfakt5;   //!
   TBranch        *b_nMuons_pfakt5;   //!
   TBranch        *b_nElectrons_pfakt5;   //!
   TBranch        *b_nNeutralHadrons_pfakt5;   //!
   TBranch        *b_nHFHadrons_pfakt5;   //!
   TBranch        *b_nHFEM_pfakt5;   //!
   TBranch        *b_eChargedHadrons_pfakt5;   //!
   TBranch        *b_eChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_eChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_ePhotons_pfakt5;   //!
   TBranch        *b_eMuons_pfakt5;   //!
   TBranch        *b_eElectrons_pfakt5;   //!
   TBranch        *b_eNeutralHadrons_pfakt5;   //!
   TBranch        *b_eHFHadrons_pfakt5;   //!
   TBranch        *b_eHFEM_pfakt5;   //!
   TBranch        *b_ptChargedHadrons_pfakt5;   //!
   TBranch        *b_ptChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_ptChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_ptPhotons_pfakt5;   //!
   TBranch        *b_ptMuons_pfakt5;   //!
   TBranch        *b_ptElectrons_pfakt5;   //!
   TBranch        *b_ptNeutralHadrons_pfakt5;   //!
   TBranch        *b_ptHFHadrons_pfakt5;   //!
   TBranch        *b_ptHFEM_pfakt5;   //!
   TBranch        *b_etaChargedHadrons_pfakt5;   //!
   TBranch        *b_etaChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_etaChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_etaPhotons_pfakt5;   //!
   TBranch        *b_etaMuons_pfakt5;   //!
   TBranch        *b_etaElectrons_pfakt5;   //!
   TBranch        *b_etaNeutralHadrons_pfakt5;   //!
   TBranch        *b_etaHFHadrons_pfakt5;   //!
   TBranch        *b_etaHFEM_pfakt5;   //!
   TBranch        *b_phiChargedHadrons_pfakt5;   //!
   TBranch        *b_phiChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_phiChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_phiPhotons_pfakt5;   //!
   TBranch        *b_phiMuons_pfakt5;   //!
   TBranch        *b_phiElectrons_pfakt5;   //!
   TBranch        *b_phiNeutralHadrons_pfakt5;   //!
   TBranch        *b_phiHFHadrons_pfakt5;   //!
   TBranch        *b_phiHFEM_pfakt5;   //!
   TBranch        *b_sumptChargedHadrons_pfakt5;   //!
   TBranch        *b_sumptChargedHadronsgoodvtx_pfakt5;   //!
   TBranch        *b_sumptChargedHadronsnoothervtx_pfakt5;   //!
   TBranch        *b_sumptPhotons_pfakt5;   //!
   TBranch        *b_sumptMuons_pfakt5;   //!
   TBranch        *b_sumptElectrons_pfakt5;   //!
   TBranch        *b_sumptNeutralHadrons_pfakt5;   //!
   TBranch        *b_sumptHFHadrons_pfakt5;   //!
   TBranch        *b_sumptHFEM_pfakt5;   //!
   TBranch        *b_nJet_pfakt7;   //!
   TBranch        *b_ptJet_pfakt7 ;   //!
   TBranch        *b_ptCorrJet_pfakt7 ;   //!
   TBranch        *b_eJet_pfakt7  ;   //!
   TBranch        *b_etaJet_pfakt7;   //!
   TBranch        *b_phiJet_pfakt7;   //!
   TBranch        *b_nJetGen_akt5;   //!
   TBranch        *b_ptJetGen_akt5 ;   //!
   TBranch        *b_eJetGen_akt5  ;   //!
   TBranch        *b_etaJetGen_akt5;   //!
   TBranch        *b_phiJetGen_akt5;   //!
   TBranch        *b_nMuonsGen_akt5;   //!
   TBranch        *b_nElectronsGen_akt5;   //!
   TBranch        *b_nPhotonsGen_akt5;   //!
   TBranch        *b_nTracksGen_akt5;   //!
   TBranch        *b_nNeutralHadronsGen_akt5;   //!
   TBranch        *b_nHFHadronsGen_akt5;   //!
   TBranch        *b_nHFEMGen_akt5;   //!
   TBranch        *b_nNeutronsGen_akt5;   //!
   TBranch        *b_nK0LGen_akt5;   //!
   TBranch        *b_nK0SGen_akt5;   //!
   TBranch        *b_nLambdasGen_akt5;   //!
   TBranch        *b_nCsiGen_akt5;   //!
   TBranch        *b_nOtherNeutralHadronsGen_akt5;   //!
   TBranch        *b_eMuonsGen_akt5;   //!
   TBranch        *b_eElectronsGen_akt5;   //!
   TBranch        *b_ePhotonsGen_akt5;   //!
   TBranch        *b_eTracksGen_akt5;   //!
   TBranch        *b_eNeutralHadronsGen_akt5;   //!
   TBranch        *b_eHFHadronsGen_akt5;   //!
   TBranch        *b_eHFEMGen_akt5;   //!
   TBranch        *b_eNeutronsGen_akt5;   //!
   TBranch        *b_eK0LGen_akt5;   //!
   TBranch        *b_eK0SGen_akt5;   //!
   TBranch        *b_eLambdasGen_akt5;   //!
   TBranch        *b_eCsiGen_akt5;   //!
   TBranch        *b_eOtherNeutralHadronsGen_akt5;   //!
   TBranch        *b_nJetGen_akt7;   //!
   TBranch        *b_ptJetGen_akt7 ;   //!
   TBranch        *b_eJetGen_akt7  ;   //!
   TBranch        *b_etaJetGen_akt7;   //!
   TBranch        *b_phiJetGen_akt7;   //!
   TBranch        *b_nvertex;   //!
   TBranch        *b_sMet;   //!
   TBranch        *b_eMet;   //!
   TBranch        *b_phiMet;   //!
   TBranch        *b_signifMet;   //!
   TBranch        *b_sCorrMet;   //!
   TBranch        *b_eCorrMet;   //!
   TBranch        *b_phiCorrMet;   //!
   TBranch        *b_signifCorrMet;   //!
   TBranch        *b_sNoHFMet;   //!
   TBranch        *b_eNoHFMet;   //!
   TBranch        *b_phiNoHFMet;   //!
   TBranch        *b_signifNoHFMet;   //!
   TBranch        *b_stcMet;   //!
   TBranch        *b_etcMet;   //!
   TBranch        *b_phitcMet;   //!
   TBranch        *b_signiftcMet;   //!
   TBranch        *b_sglobalPfMet;   //!
   TBranch        *b_eglobalPfMet;   //!
   TBranch        *b_phiglobalPfMet;   //!
   TBranch        *b_signifglobalPfMet;   //!
   TBranch        *b_scentralPfMet;   //!
   TBranch        *b_ecentralPfMet;   //!
   TBranch        *b_phicentralPfMet;   //!
   TBranch        *b_signifcentralPfMet;   //!
   TBranch        *b_eassocPfMet;   //!
   TBranch        *b_phiassocPfMet;   //!
   TBranch        *b_signifassocPfMet;   //!
   TBranch        *b_eassocOtherVtxPfMet;   //!
   TBranch        *b_phiassocOtherVtxPfMet;   //!
   TBranch        *b_signifassocOtherVtxPfMet;   //!
   TBranch        *b_etrkPfMet;   //!
   TBranch        *b_phitrkPfMet;   //!
   TBranch        *b_signiftrkPfMet;   //!
   TBranch        *b_ecleanPfMet;   //!
   TBranch        *b_phicleanPfMet;   //!
   TBranch        *b_signifcleanPfMet;   //!
   TBranch        *b_globalPfSums;   //!
   TBranch        *b_spfMet;   //!
   TBranch        *b_epfMet;   //!
   TBranch        *b_phipfMet;   //!
   TBranch        *b_signifpfMet;   //!
   TBranch        *b_spfMetType1;   //!
   TBranch        *b_epfMetType1;   //!
   TBranch        *b_phipfMetType1;   //!
   TBranch        *b_signifpfMetType1;   //!
   TBranch        *b_sMetGen;   //!
   TBranch        *b_eMetGen;   //!
   TBranch        *b_phiMetGen;   //!
   TBranch        *b_signifMetGen;   //!
   TBranch        *b_sMetGen2;   //!
   TBranch        *b_eMetGen2;   //!
   TBranch        *b_phiMetGen2;   //!
   TBranch        *b_vxMC;   //!
   TBranch        *b_vyMC;   //!
   TBranch        *b_vzMC;   //!
   TBranch        *b_vx;   //!
   TBranch        *b_vy;   //!
   TBranch        *b_vz;   //!
   TBranch        *b_vntracks;   //!
   TBranch        *b_vchi2;   //!
   TBranch        *b_vndof;   //!
   TBranch        *b_vlogsumpt2;   //!
   TBranch        *b_nPreselPhotonPairs;   //!
   TBranch        *b_indexPreselPhot1;   //!
   TBranch        *b_indexPreselPhot2;   //!
   TBranch        *b_vrankPhotonPairs;   //!
   TBranch        *b_vevtMvaPhotonPairs;   //!
   TBranch        *b_vevtProbPhotonPairs;   //!
   TBranch        *b_vptbalPhotonPairs;   //!
   TBranch        *b_vptasymPhotonPairs;   //!
   TBranch        *b_nHLT;   //!
   TBranch        *b_hltNamesLen;   //!
   TBranch        *b_HLTNames;   //!
   TBranch        *b_HLTResults;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_electron_px;   //!
   TBranch        *b_electron_py;   //!
   TBranch        *b_electron_pz;   //!
   TBranch        *b_electron_vx;   //!
   TBranch        *b_electron_vy;   //!
   TBranch        *b_electron_vz;   //!
   TBranch        *b_electron_pt;   //!
   TBranch        *b_electron_eta;   //!
   TBranch        *b_electron_phi;   //!
   TBranch        *b_electron_energy;   //!
   TBranch        *b_electron_ecalEnergy;   //!
   TBranch        *b_electron_trackPatVtx;   //!
   TBranch        *b_electron_charge;   //!
   TBranch        *b_electron_fBrem;   //!
   TBranch        *b_electron_dist;   //!
   TBranch        *b_electron_dcot;   //!
   TBranch        *b_electron_misHits;   //!
   TBranch        *b_electron_matchedConv;   //!
   TBranch        *b_electron_seedType;   //!
   TBranch        *b_electron_EoP;   //!
   TBranch        *b_electron_OneOverEMinusOneOverP;   //!
   TBranch        *b_electron_r9;   //!
   TBranch        *b_electron_nSubClusters;   //!
   TBranch        *b_electron_trkIso;   //!
   TBranch        *b_electron_ecalIso;   //!
   TBranch        *b_electron_hcalIso;   //!
   TBranch        *b_electron_trkIso03;   //!
   TBranch        *b_electron_ecalIso03;   //!
   TBranch        *b_electron_hcalIso03;   //!
   TBranch        *b_electron_SigmaIetaIeta;   //!
   TBranch        *b_electron_SigmaIphiIphi;   //!
   TBranch        *b_electron_dEtaIn;   //!
   TBranch        *b_electron_dPhiIn;   //!
   TBranch        *b_electron_HoE;   //!
   TBranch        *b_electron_pFlowMVA;   //!
   TBranch        *b_electron_sc_energy;   //!
   TBranch        *b_electron_sc_eta;   //!
   TBranch        *b_electron_sc_phi;   //!
   TBranch        *b_electron_mvaNonTrig;   //!
   TBranch        *b_electron_mvaTrig;   //!
   TBranch        *b_electron_chHad03Iso;   //!
   TBranch        *b_electron_nHad03Iso;   //!
   TBranch        *b_electron_phot03Iso;   //!
   TBranch        *b_electron_chHad04Iso;   //!
   TBranch        *b_electron_nHad04Iso;   //!
   TBranch        *b_electron_phot04Iso;   //!
   TBranch        *b_electron_chHad05Iso;   //!
   TBranch        *b_electron_nHad05Iso;   //!
   TBranch        *b_electron_phot05Iso;   //!
   TBranch        *b_isBeamHaloGlobalLoosePass;   //!
   TBranch        *b_isBeamHaloGloablTightPass;   //!
   TBranch        *b_isBeamHaloHcalLoosePass;   //!
   TBranch        *b_isBeamHaloHcalTightPass;   //!
   TBranch        *b_isBeamHaloCSCLoosePass;   //!
   TBranch        *b_isBeamHaloCSCTightPass;   //!
   TBranch        *b_isBeamHaloEcalLoosePass;   //!
   TBranch        *b_isBeamHaloEcalTightPass;   //!
   TBranch        *b_isBeamHaloIDTightPass;   //!
   TBranch        *b_isBeamHaloIDLoosePass;   //!
   TBranch        *b_isSmellsLikeHalo_Tag;   //!
   TBranch        *b_isLooseHalo_Tag;   //!
   TBranch        *b_isTightHalo_Tag;   //!
   TBranch        *b_isExtremeTightHalo_Tag;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_Muon_px;   //!
   TBranch        *b_Muon_py;   //!
   TBranch        *b_Muon_pz;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_energy;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_isGlobalMuon;   //!
   TBranch        *b_Muon_isTrackerMuon;   //!
   TBranch        *b_Muon_isStandAloneMuon;   //!
   TBranch        *b_Muon_trkLayerWithMeas;   //!
   TBranch        *b_Muon_InnerTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterPoint_x;   //!
   TBranch        *b_Muon_OuterPoint_y;   //!
   TBranch        *b_Muon_OuterPoint_z;   //!
   TBranch        *b_Muon_isPFMuon;   //!
   TBranch        *b_Muon_pfiso04_chHad;   //!
   TBranch        *b_Muon_pfiso04_chPar;   //!
   TBranch        *b_Muon_pfiso04_nHad;   //!
   TBranch        *b_Muon_pfiso04_Phot;   //!
   TBranch        *b_Muon_pfiso04_PUPt;   //!
   TBranch        *b_Muon_pfiso03_chHad;   //!
   TBranch        *b_Muon_pfiso03_chPar;   //!
   TBranch        *b_Muon_pfiso03_nHad;   //!
   TBranch        *b_Muon_pfiso03_Phot;   //!
   TBranch        *b_Muon_pfiso03_PUPt;   //!
   TBranch        *b_Muon_InnerPoint_x;   //!
   TBranch        *b_Muon_InnerPoint_y;   //!
   TBranch        *b_Muon_InnerPoint_z;   //!
   TBranch        *b_Muon_trackIso;   //!
   TBranch        *b_Muon_ecalIso;   //!
   TBranch        *b_Muon_hcalIso;   //!
   TBranch        *b_Muon_relIso;   //!
   TBranch        *b_Muon_normChi2;   //!
   TBranch        *b_Muon_validHits;   //!
   TBranch        *b_Muon_tkHits;   //!
   TBranch        *b_Muon_pixHits;   //!
   TBranch        *b_Muon_numberOfMatches;   //!
   TBranch        *b_nCosmicMuons;   //!
   TBranch        *b_CosmicMuon_px;   //!
   TBranch        *b_CosmicMuon_py;   //!
   TBranch        *b_CosmicMuon_pz;   //!
   TBranch        *b_CosmicMuon_pt;   //!
   TBranch        *b_CosmicMuon_eta;   //!
   TBranch        *b_CosmicMuon_phi;   //!
   TBranch        *b_CosmicMuon_energy;   //!
   TBranch        *b_CosmicMuon_charge;   //!
   TBranch        *b_CosmicMuon_isGlobalMuon;   //!
   TBranch        *b_CosmicMuon_isTrackerMuon;   //!
   TBranch        *b_CosmicMuon_isStandAloneMuon;   //!
   TBranch        *b_CosmicMuon_InnerTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterPoint_z;   //!
   TBranch        *b_Xsec;   //!

   tree_reader_up(TTree *tree=0);
   virtual ~tree_reader_up();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif
