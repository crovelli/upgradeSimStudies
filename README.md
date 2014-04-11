upgradeSimStudies
=================

simulation studies for upgrade



--------------------------------------------
To make reduced ntuples out of Roma g+jet ones:
cd src
make clean
make
./tmp/singlegammaApp_upgrade ../data/myListReduction__noAg_NoPU_complete.txt red_noAgeing_noPU.root

Once you have the reduced trees, to make histos with gamma infos
root -b
.L upgradeFakeAnalysis.C++
upgradeFakeAnalysis pippo
pippo.Loop

Basic plots can be done running makePlots*C on the output