{
  // To be changed
  bool vsPU      = false;
  bool noAgeing  = false;
  bool ageing150 = false;
  bool ageing300 = false;   // not ready yet
  // 
  bool vsAgeing  = true;
  bool noPU      = true;
  bool pu20      = false;
  bool pu70      = false;
  bool pu140     = false;

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetOptFile(1);


  // -------------------------------------------------------------
  // Loading histos
  TH1F *H_vtx[4];
  TH1F *H_matchedEB_convSafe[4],   *H_matchedEB_HoE[4],        *H_matchedEB_sIeIe[4];
  TH1F *H_unmatchedEB_convSafe[4], *H_unmatchedEB_HoE[4],      *H_unmatchedEB_sIeIe[4];

  TFile *myFile;
  int numOfFiles = 4;
  if (vsAgeing) numOfFiles = 2;   // chiara: will become 3 when 300 is also ready

  for (int ii=0; ii<numOfFiles; ii++) {  
      
    // the wanted file - studies vs pu for different ageings
    if (vsPU && noAgeing) {
      if (ii==0) myFile = new TFile("histoFile_noAgeing_noPU.root");
      if (ii==1) myFile = new TFile("histoFile_noAgeing_PU20.root");
      if (ii==2) myFile = new TFile("histoFile_noAgeing_PU70.root");
      if (ii==3) myFile = new TFile("histoFile_noAgeing_PU140.root");
    } else if (vsPU && ageing150) {
      if (ii==0) myFile = new TFile("histoFile_ageing150_noPU.root");
      if (ii==1) myFile = new TFile("histoFile_ageing150_PU20.root");
      if (ii==2) myFile = new TFile("histoFile_ageing150_PU70.root");
      if (ii==3) myFile = new TFile("histoFile_ageing150_PU140.root");
    } else if (vsPU && ageing150) {
      // not ready yet
    }

    // the wanted file - studies vs ageing for different PU
    if (vsAgeing && noPU) {
      if (ii==0) myFile = new TFile("histoFile_noAgeing_noPU.root");
      if (ii==1) myFile = new TFile("histoFile_ageing150_noPU.root");
    } else if (vsAgeing && pu20) {
      if (ii==0) myFile = new TFile("histoFile_noAgeing_PU20.root");
      if (ii==1) myFile = new TFile("histoFile_ageing150_PU20.root");
    } else if (vsAgeing && pu70) {
      if (ii==0) myFile = new TFile("histoFile_noAgeing_PU70.root");
      if (ii==1) myFile = new TFile("histoFile_ageing150_PU70.root");
    } else if (vsAgeing && pu140) {
      if (ii==0) myFile = new TFile("histoFile_noAgeing_PU140.root");
      if (ii==1) myFile = new TFile("histoFile_ageing150_PU140.root");
    }


    // histos
    H_vtx[ii] = (TH1F*)myFile->Get("H_vtx");

    H_matchedEB_convSafe[ii]   = (TH1F*)myFile->Get("H_matchedEB_convSafe");
    H_matchedEB_HoE[ii]        = (TH1F*)myFile->Get("H_matchedEB_HoE");
    H_matchedEB_sIeIe[ii]      = (TH1F*)myFile->Get("H_matchedEB_sIeIe");

    H_unmatchedEB_convSafe[ii] = (TH1F*)myFile->Get("H_unmatchedEB_convSafe");
    H_unmatchedEB_HoE[ii]      = (TH1F*)myFile->Get("H_unmatchedEB_HoE");
    H_unmatchedEB_sIeIe[ii]    = (TH1F*)myFile->Get("H_unmatchedEB_sIeIe");
  }    


  // --------------------------------------------------
  // general cosmetics + for real/fake plots 
  for (int ii=0; ii<numOfFiles; ii++) {

    H_matchedEB_convSafe[ii]  ->SetLineColor(2);
    H_unmatchedEB_convSafe[ii]->SetLineColor(4);
    H_matchedEB_convSafe[ii]  ->SetTitle("");
    H_unmatchedEB_convSafe[ii]->SetTitle("");
    H_matchedEB_convSafe[ii]  ->GetXaxis()->SetTitle("conv.safe electron veto");
    H_unmatchedEB_convSafe[ii]->GetXaxis()->SetTitle("conv.safe electron veto");

    H_matchedEB_HoE[ii]  ->SetLineColor(2);
    H_unmatchedEB_HoE[ii]->SetLineColor(4);
    H_matchedEB_HoE[ii]  ->SetTitle("");
    H_unmatchedEB_HoE[ii]->SetTitle("");
    H_matchedEB_HoE[ii]  ->GetXaxis()->SetTitle("H/E");
    H_unmatchedEB_HoE[ii]->GetXaxis()->SetTitle("H/E");

    H_matchedEB_sIeIe[ii]  ->SetLineColor(2);
    H_unmatchedEB_sIeIe[ii]->SetLineColor(4);
    H_matchedEB_sIeIe[ii]  ->SetTitle("");
    H_unmatchedEB_sIeIe[ii]->SetTitle("");
    H_matchedEB_sIeIe[ii]  ->GetXaxis()->SetTitle("#sigma I#etaI#eta");
    H_unmatchedEB_sIeIe[ii]->GetXaxis()->SetTitle("#sigma I#etaI#eta");
  }


  // ----------------------------------------------------
  // plots: comparing S vs B
  TLegend *leg =new TLegend(0.15,0.60,0.50,0.75);
  leg->SetBorderSize(0);
  leg->SetLineColor(0);
  leg->SetFillColor(0);
  leg->AddEntry(H_matchedEB_convSafe[0],   "real #gamma", "l");
  leg->AddEntry(H_unmatchedEB_convSafe[0], "fake #gamma", "l");

  TCanvas c("c","",1);
  for (int ii=0; ii<numOfFiles; ii++) {

    c.SetLogy(0);    

    char thefile[200];
    char thefile2[200];
    char thename[200];
    if (vsPU) {
      if (ii==0) sprintf(thefile,"%s","noPU");
      if (ii==1) sprintf(thefile,"%s","pu20");
      if (ii==2) sprintf(thefile,"%s","pu70");
      if (ii==3) sprintf(thefile,"%s","pu140");
      if (noAgeing)  sprintf(thefile2,"%s","noAgeing");
      if (ageing150) sprintf(thefile2,"%s","Ageing150");
    } 

    if (vsAgeing) {
      if (ii==0) sprintf(thefile,"%s","noAgeing");
      if (ii==1) sprintf(thefile,"%s","Ageing150");
      if (noPU)  sprintf(thefile2,"%s","noPU");
      if (pu20)  sprintf(thefile2,"%s","PU20");
      if (pu70)  sprintf(thefile2,"%s","PU70");
      if (pu140) sprintf(thefile2,"%s","PU140");
    }

    H_matchedEB_convSafe[ii]->DrawNormalized();
    H_unmatchedEB_convSafe[ii]->DrawNormalized("same");
    leg->Draw();
    sprintf(thename, "convSafe_%s_%s.png", thefile, thefile2);
    c.SaveAs(thename);

    H_matchedEB_sIeIe[ii]->DrawNormalized();
    H_unmatchedEB_sIeIe[ii]->DrawNormalized("same");
    leg->Draw();
    sprintf(thename, "sIeIe_%s_%s.png", thefile, thefile2);
    c.SaveAs(thename);

    c.SetLogy(1);
    H_matchedEB_HoE[ii]->DrawNormalized();
    H_unmatchedEB_HoE[ii]->DrawNormalized("same");
    leg->Draw();
    sprintf(thename, "HoE_%s_%s.png", thefile, thefile2);
    c.SaveAs(thename);
  }  


  // ------------------------------------------------------
  // cosmetics for plots vs pu
  for (int ii=0; ii<numOfFiles; ii++) {
    int thecolor = ii+1;
    H_vtx[ii]   -> SetLineColor(thecolor);
    H_matchedEB_convSafe[ii]   -> SetLineColor(thecolor);
    H_unmatchedEB_convSafe[ii] -> SetLineColor(thecolor);
    H_matchedEB_sIeIe[ii]   -> SetLineColor(thecolor);
    H_unmatchedEB_sIeIe[ii] -> SetLineColor(thecolor);
    H_matchedEB_HoE[ii]     -> SetLineColor(thecolor);
    H_unmatchedEB_HoE[ii]   -> SetLineColor(thecolor);
  }

  TLegend *leg2 =new TLegend(0.15,0.60,0.50,0.75);
  leg2->SetBorderSize(0);
  leg2->SetLineColor(0);
  leg2->SetFillColor(0);
  if (vsPU) {
    leg2->AddEntry(H_matchedEB_convSafe[0], "no pu", "l");
    leg2->AddEntry(H_matchedEB_convSafe[1], "pu 20", "l");
    leg2->AddEntry(H_matchedEB_convSafe[2], "pu 70", "l");
    leg2->AddEntry(H_matchedEB_convSafe[3], "pu 140", "l");
  } else if (vsAgeing) {
    leg2->AddEntry(H_matchedEB_convSafe[0], "no ageing", "l");
    leg2->AddEntry(H_matchedEB_convSafe[1], "ageing 150", "l");
  }

  // -------------------------------------------------------
  // pileup evolution on real gammas
  TCanvas c2("c2","",1);
  if (vsPU) {

    c2.SetLogy(0);

    char thefile3[200];
    char thename3[200];
    if (noAgeing)  sprintf(thefile3,"%s","noAgeing");
    if (ageing150) sprintf(thefile3,"%s","Ageing150");

    H_vtx[0]->DrawNormalized();
    H_vtx[1]->DrawNormalized("same");
    H_vtx[2]->DrawNormalized("same");
    H_vtx[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "vtx_vsPU_%s.png", thefile3);
    c2.SaveAs(thename3);

    H_matchedEB_convSafe[0]->DrawNormalized();
    H_matchedEB_convSafe[1]->DrawNormalized("same");
    H_matchedEB_convSafe[2]->DrawNormalized("same");
    H_matchedEB_convSafe[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "matchedEB_convSafe_vsPU_%s.png", thefile3);
    c2.SaveAs(thename3);
    
    H_matchedEB_sIeIe[0]->DrawNormalized();
    H_matchedEB_sIeIe[1]->DrawNormalized("same");
    H_matchedEB_sIeIe[2]->DrawNormalized("same");
    H_matchedEB_sIeIe[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "matchedEB_sIeIe_vsPU_%s.png", thefile3);
    c2.SaveAs(thename3);
    
    c2.SetLogy();
    H_matchedEB_HoE[0]->DrawNormalized();
    H_matchedEB_HoE[1]->DrawNormalized("same");
    H_matchedEB_HoE[2]->DrawNormalized("same");
    H_matchedEB_HoE[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "matchedEB_HoE_vsPU_%s.png", thefile3);
    c2.SaveAs(thename3);
  }


  // -------------------------------------------------------
  // pileup evolution on fake gammas
  TCanvas c22("c22","",1);
  if (vsPU) {

    c22.SetLogy(0);

    char thefile3[200];
    char thename3[200];
    if (noAgeing)  sprintf(thefile3,"%s","noAgeing");
    if (ageing150) sprintf(thefile3,"%s","Ageing150");

    H_unmatchedEB_convSafe[0]->DrawNormalized();
    H_unmatchedEB_convSafe[1]->DrawNormalized("same");
    H_unmatchedEB_convSafe[2]->DrawNormalized("same");
    H_unmatchedEB_convSafe[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "unmatchedEB_convSafe_vsPU_%s.png", thefile3);
    c22.SaveAs(thename3);
    
    H_unmatchedEB_sIeIe[0]->DrawNormalized();
    H_unmatchedEB_sIeIe[1]->DrawNormalized("same");
    H_unmatchedEB_sIeIe[2]->DrawNormalized("same");
    H_unmatchedEB_sIeIe[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "unmatchedEB_sIeIe_vsPU_%s.png", thefile3);
    c22.SaveAs(thename3);
    
    c22.SetLogy();
    H_unmatchedEB_HoE[0]->DrawNormalized();
    H_unmatchedEB_HoE[1]->DrawNormalized("same");
    H_unmatchedEB_HoE[2]->DrawNormalized("same");
    H_unmatchedEB_HoE[3]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename3, "unmatchedEB_HoE_vsPU_%s.png", thefile3);
    c22.SaveAs(thename3);
  }


  // -------------------------------------------------------
  // ageing evolution on real gammas
  TCanvas c3("c3","",1);
  if (vsAgeing) {

    c3.SetLogy(0);

    char thefile4[200];
    char thename4[200];
    if (noPU)  sprintf(thefile4,"%s","noPU");
    if (pu20)  sprintf(thefile4,"%s","pu20");
    if (pu70)  sprintf(thefile4,"%s","pu70");
    if (pu140) sprintf(thefile4,"%s","pu140");

    H_vtx[0]->DrawNormalized();
    H_vtx[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename4, "vtx_vsAgeing_%s.png", thefile4);
    c3.SaveAs(thename4);

    H_matchedEB_convSafe[0]->DrawNormalized();
    H_matchedEB_convSafe[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename4, "matchedEB_convSafe_vsAgeing_%s.png", thefile4);
    c3.SaveAs(thename4);
    
    H_matchedEB_sIeIe[0]->DrawNormalized();
    H_matchedEB_sIeIe[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename4, "matchedEB_sIeIe_vsAgeing_%s.png", thefile4);
    c3.SaveAs(thename4);
    
    c3.SetLogy();
    H_matchedEB_HoE[0]->DrawNormalized();
    H_matchedEB_HoE[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename4, "matchedEB_HoE_vsAgeing_%s.png", thefile4);
    c3.SaveAs(thename4);
  }


  // -------------------------------------------------------
  // ageing evolution on fake gammas
  TCanvas c33("c33","",1);
  if (vsAgeing) {

    c33.SetLogy(0);

    char thefile5[200];
    char thename5[200];
    if (noPU)  sprintf(thefile5,"%s","noPU");
    if (pu20)  sprintf(thefile5,"%s","pu20");
    if (pu70)  sprintf(thefile5,"%s","pu70");
    if (pu140) sprintf(thefile5,"%s","pu140");

    H_unmatchedEB_convSafe[0]->DrawNormalized();
    H_unmatchedEB_convSafe[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename5, "unmatchedEB_convSafe_vsAgeing_%s.png", thefile5);
    c33.SaveAs(thename5);
    
    H_unmatchedEB_sIeIe[0]->DrawNormalized();
    H_unmatchedEB_sIeIe[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename5, "unmatchedEB_sIeIe_vsAgeing_%s.png", thefile5);
    c33.SaveAs(thename5);
    
    c33.SetLogy();
    H_unmatchedEB_HoE[0]->DrawNormalized();
    H_unmatchedEB_HoE[1]->DrawNormalized("same");
    leg2->Draw();
    sprintf(thename5, "unmatchedEB_HoE_vsAgeing_%s.png", thefile5);
    c33.SaveAs(thename5);
  }

}
