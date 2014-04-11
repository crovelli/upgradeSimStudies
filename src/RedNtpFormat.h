#define NPHOTMAX 50
#define NPHOTGENMAX 100

// Declaration of leaf types
Int_t           run;
Int_t           event;
Int_t           lumi;
Float_t         nvtx;
Int_t           LOGamma;
Int_t           ISRGamma;
Int_t           FSRGamma;
Int_t           npu;
Int_t           nPhot_gen;
Float_t         deltaRMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Float_t         ptTrueMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Float_t         etaMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Float_t         phiMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Float_t         ptRecoMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Float_t         iRecoPhotMatch_gen[NPHOTGENMAX]; //[nPhot_gen]
Int_t           nPhot_presel;
Float_t         ptPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         ePhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         etascPhot_presel  [NPHOTMAX];   //[nPhot_presel]
Float_t         etaPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         phiPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_jurECAL03_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_twrHCAL03_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_hlwTrack03_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_jurECAL04_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_twrHCAL04_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_hlwTrack04_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoCharged03ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoCharged04ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoPhotons03ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoPhotons04ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoNeutrals03ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_pfIsoNeutrals04ForCiC_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         e4_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         e9_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         e25_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_scetawid_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_scphiwid_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_lambdaRatio_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         pid_HoverE_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         sEtaEtaPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         sEtaPhiPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         s4RatioPhot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         r9Phot_presel[NPHOTMAX];   //[nPhot_presel]
Float_t         rhoAllJets;
Float_t         rhoPF;
Float_t         rr_presel[NPHOTMAX];   //[nPhot_presel]
Int_t           isMatchedPhot[NPHOTMAX];   //[nPhot_presel]
Int_t           iMatchedPhot[NPHOTMAX];   //[nPhot_presel] 
Int_t           val_pho_isconv_presel[NPHOTMAX];   //[nPhot_presel]
Int_t           vtxId;

std::vector<std::string>  *firedHLTNames;


   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_LOGamma;   //!
   TBranch        *b_ISRGamma;   //!
   TBranch        *b_FSRGamma;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_nPhot_gen;   //!
   TBranch        *b_deltaRMatch_gen; //!
   TBranch        *b_ptTrueMatch_gen; //!
   TBranch        *b_etaMatch_gen; //!
   TBranch        *b_phiMatch_gen; //!
   TBranch        *b_ptRecoMatch_gen; //!
   TBranch        *b_iRecoPhotMatch_gen; //!
   TBranch        *b_nPhot_presel;   //!
   TBranch        *b_ptPhot_presel;   //!
   TBranch        *b_ePhot_presel;   //!
   TBranch        *b_etascPhot_presel  ;   //!
   TBranch        *b_etaPhot_presel;   //!
   TBranch        *b_phiPhot_presel;   //!
   TBranch        *b_pid_jurECAL03_presel;   //!
   TBranch        *b_pid_twrHCAL03_presel;   //!
   TBranch        *b_pid_hlwTrack03_presel;   //!
   TBranch        *b_pid_jurECAL04_presel;   //!
   TBranch        *b_pid_twrHCAL04_presel;   //!
   TBranch        *b_pid_hlwTrack04_presel;   //!
   TBranch        *b_pid_pfIsoCharged03ForCiC_presel;   //!
   TBranch        *b_pid_pfIsoCharged04ForCiC_presel;   //!
   TBranch        *b_pid_pfIsoPhotons03ForCiC_presel;   //!
   TBranch        *b_pid_pfIsoPhotons04ForCiC_presel;   //!
   TBranch        *b_pid_pfIsoNeutrals03ForCiC_presel;   //!
   TBranch        *b_pid_pfIsoNeutrals04ForCiC_presel;   //!
   TBranch        *b_e4_presel;
   TBranch        *b_e9_presel;
   TBranch        *b_e25_presel;
   TBranch        *b_pid_scetawid_presel;   //!
   TBranch        *b_pid_scphiwid_presel;   //!
   TBranch        *b_pid_lambdaRatio_presel;   //!
   TBranch        *b_pid_HoverE_presel;   //!
   TBranch        *b_sEtaEtaPhot_presel;   //!
   TBranch        *b_sEtaPhiPhot_presel;   //!
   TBranch        *b_s4RatioPhot_presel;   //!
   TBranch        *b_r9Phot_presel;   //!
   TBranch        *b_rhoAllJets;   //!
   TBranch        *b_rhoPF;   //!
   TBranch        *b_rr_presel;   //!
   TBranch        *b_isMatchedPhot;   //!
   TBranch        *b_iMatchedPhot;   //! 
   TBranch        *b_val_pho_isconv_presel;   //!
   TBranch        *b_vtxId;   //!

