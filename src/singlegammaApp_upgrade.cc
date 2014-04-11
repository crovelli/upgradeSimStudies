#include <stdlib.h>
#include <iostream>
#include <string>

#include <TTree.h>
#include <TChain.h>
#include <TROOT.h>
#include <TFile.h>
#include <TH2.h>
#include <TH1.h>
#include <TVector2.h>
#include <TVector3.h>

#include "SingleGammaTreeUpgrade.h"
#include "IsGJet.h"

using namespace std;

int main(int argc, char* argv[]) {

  if(argc<2 || argc>3) {
    cout << "Usage:  ./tmp/singlegammaApp listfile outputfile\n"
	 << "  listfile:    list of root files incusing protocol eg dcap:/// .....\n"
	 << "  outputfile:  name of output root file  eg output.root\n"
	 << endl;
    exit(-1);
  }
  
  // Input list
  char listName[500];
  sprintf(listName,argv[1]); 
  
  // Output filename (.root)  
  TString OutputFileName(argv[2]);
  
  // Name of input tree objects in (.root) files 
  char treeName[100] = "myanalysis/pippo";

  // fai TChain
  TChain *chain = new TChain(treeName);
  char pName[500];
  ifstream is(listName);
  if(! is.good()) {
    cout << "int main() >> ERROR : file " << listName << " not read" << endl;
    is.close();
    exit(-1);
  }
  cout << "Reading list : " << listName << " ......." << endl;
  
  while( is.getline(pName, 500, '\n') ) {
    if (pName[0] == '#') continue;
    chain->Add(pName); 
  }
  is.close();
  
  // filter for 2gam + jets. this is included in GJets samples but we use dedicated DiPhotonjets-madgraph
  int isGJetQCD = IsGJet(listName);
  
  // compute equivalent luminosity
  Long64_t ntot = 1;
  cout << "#events: " << ntot << endl;
  
  // run analysis code
  SingleGammaTreeUpgrade tool(chain, OutputFileName);
  
  std::cout << "DONE with settings starting loop" << std::endl;
  
  tool.Loop();
}
