//load ROOT libraryes
#include "TStyle.h"//plot style
#include "TMath.h"
#include "TH1.h"// 1D histogram



void makeaxishisto_small(TH1D *h){
  h-> GetXaxis() -> CenterTitle();
  h -> GetYaxis() -> CenterTitle();

  
  h->SetTitleSize(0.05,"XZ");
  h->SetTitleSize(0.05,"Y");
  h->GetYaxis()->SetTitleOffset(0.8);
  h->GetXaxis()->SetTitleOffset(1);
  h->GetXaxis()->SetLabelSize(0.05);
  h->GetYaxis()->SetLabelSize(0.05);
  h->GetXaxis()->SetNdivisions(5);
  h->GetYaxis()->SetNdivisions(5);
  
  h->SetLineWidth(2);
  //  gStyle->SetTitleSize(0.072,"t");
  gStyle->SetTitleSize(0.07,"t");
  gStyle->SetTitleX(0.54f);
  gStyle->SetTitleW(0.8f);
}



