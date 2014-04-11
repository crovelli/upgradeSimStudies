#ifndef SingleGammaTreeUpgrade_h
#define SingleGammaTreeUpgrade_h

#include "tree_reader_up.h"

#include "TLorentzVector.h"

#include <TFile.h>
#include <TMath.h>
#include <vector>
#include <string>
#include <TChain.h>

#include "TMVA/Reader.h"

using std::string;
using std::vector;

#define NGENJETS 200
#define NMC 200

class SingleGammaTreeUpgrade : public tree_reader_up {

public:
  
  SingleGammaTreeUpgrade(TTree *tree=0, const TString& outname="redntp.root");
  virtual ~SingleGammaTreeUpgrade();

  virtual void Loop();

private:
  TFile* hOutputFile ;
  TTree * ana_tree ;
  
  virtual vector<int> firstones(Float_t * vec, vector<bool> *asso, int number=4);

  // gen level info
  int countLOGenGamma();
  int countISRGenGamma();
  int countFSRGenGamma();

  int runRN;
  int eventRN;
  int lumi;
  int LOGamma;
  int ISRGamma;
  int FSRGamma;
  int npu;
  int vtxId;
  float nvtx;
};
#endif
