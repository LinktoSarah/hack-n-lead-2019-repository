//load c++ libraryes
#include <fstream>
#include <sstream>
#include <vector>

//load ROOT libraryes
#include "TStyle.h"//plot style
#include "TF1.h"//functions
#include "TCanvas.h"
#include "TLegend.h"
#include "TString.h"
#include "TMath.h"
#include "TH1.h"// 1D histogram


//user defined functions
#include "../include/MakeAxis.C"


void read(string filename = "../../dataSource/Variables_used.txt"){

  int yearRegistration;
  string citizenship;
  int doExessiveWork;
  string majorityStatus, gender;
  int SexualAbuse, FinancialAccess;
  int meansOfControlSexualAbuse;
  int meansOfControlPhysicalAbuse, meansOfControlPsychoactiveSubstances, isForcedLabour;
  char line[100000];
  int isinAsia =0;
  ifstream in;
  in.open(filename);
  //Distribution of year of registration for Thailand (TH)
  TH1D *h_YearDist = new TH1D("h_YearDist", "Year of reagistration", 19, 2000.5,2019.5);
  makeaxishisto_small(h_YearDist);
  
  do{
    //
    //  in >> yearRegistration >> citizenship >>  doExessiveWork >> majorityStatus >> gender >> FinancialAccess ;
    in >> yearRegistration >> citizenship >>  doExessiveWork >> majorityStatus >> meansOfControlSexualAbuse >>  meansOfControlPhysicalAbuse >> meansOfControlPsychoactiveSubstances >> isForcedLabour;
    //  cout << "yearRegistration " << yearRegistration << " citizenship " << citizenship << " doExessiveWork " << doExessiveWork << " majorityStatus " << majorityStatus << " SexualAbuse "<< SexualAbuse <<  endl;//test reading the line
    //if(SexualAbuse==0)continue;
    if(citizenship.find("KP") != std::string::npos || citizenship.find("KR") != std::string::npos || citizenship.find("AF") != std::string::npos || citizenship.find("PK") != std::string::npos || citizenship.find("KH") != std::string::npos || citizenship.find("IR") != std::string::npos || citizenship.find("NP") != std::string::npos || citizenship.find("MN") != std::string::npos || citizenship.find("MM") != std::string::npos || citizenship.find("BN") != std::string::npos || citizenship.find("PG") != std::string::npos || citizenship.find("LA") != std::string::npos || citizenship.find("TH") != std::string::npos || citizenship.find("PH") != std::string::npos || citizenship.find("ID") != std::string::npos || citizenship.find("TL") != std::string::npos  || citizenship.find("MY") != std::string::npos || citizenship.find("IN") != std::string::npos || citizenship.find("VN") != std::string::npos || citizenship.find("BD") != std::string::npos  || citizenship.find("SG") != std::string::npos || citizenship.find("CN") != std::string::npos || citizenship.find("CN") != std::string::npos || citizenship.find("LK") != std::string::npos || citizenship.find("HK") != std::string::npos || citizenship.find("TW") != std::string::npos || citizenship.find("JP") != std::string::npos)isinAsia =1;//looking only for  Asia countries 
    if(isinAsia ==0)continue;
    if(majorityStatus.find("-99") != std::string::npos)continue;//exclude NA  data of the majority status
    if(majorityStatus.find("Adult") != std::string::npos)continue;//exlude Adults
    int forcedlabor =0;
    if(isForcedLabour ==1)forcedlabor =1;
    if(isForcedLabour ==0)forcedlabor=2;
    int ControlPsychoactiveSubstances =0;
    if(meansOfControlPsychoactiveSubstances ==1)ControlPsychoactiveSubstances =1;
    if(meansOfControlPsychoactiveSubstances ==0)ControlPsychoactiveSubstances =2;

    int ControlPhysicalAbuse =0;
    if( meansOfControlPhysicalAbuse ==1)ControlPhysicalAbuse  =1;
    if( meansOfControlPhysicalAbuse ==0)ControlPhysicalAbuse =2;

    

    
    // if(isForcedLabour <1)continue;//forced labour children
    // if(meansOfControlPsychoactiveSubstance <1)continue;
    // if(meansOfControlPhysicalAbuse <1)continue;
    
    // if(FinancialAccess <1)continue;
    
    //  if(forcedlabor==2)h_YearDist->Fill(yearRegistration);
    //  if(ControlPsychoactiveSubstances==1)h_YearDist->Fill(yearRegistration);

    //  if(ControlPhysicalAbuse==2)
    h_YearDist->Fill(yearRegistration);
    
    cout << "after selection " << endl;
    cout << "yearRegistration " << yearRegistration << " citizenship " << citizenship << " doExessiveWork " << doExessiveWork << " majorityStatus " << majorityStatus << " SexualAbuse "<< SexualAbuse << "meansOfControlSexualAbuse " <<  meansOfControlSexualAbuse << " meansOfControlPhysicalAbuse " <<  meansOfControlPhysicalAbuse << " meansOfControlPsychoactiveSubstances " << meansOfControlPsychoactiveSubstances << " isForcedLabour " << isForcedLabour <<  endl;
    
  }
  while(in.getline(line,100000));
  //canvas
 
  TCanvas *canv = new TCanvas("canv", "canvas", 600,400);
  canv->cd();
  gPad->SetLeftMargin(0.2);
  gPad->SetBottomMargin(0.2);
  h_YearDist->SetTitle("");
  h_YearDist->GetYaxis()->SetTitle("Number of minors");
  h_YearDist->GetYaxis()->SetTitleOffset(1.3);
  h_YearDist->GetXaxis()->SetTitle("Year");
  h_YearDist->SetFillColor(kBlue);
  h_YearDist->SetFillStyle(3003);
  h_YearDist->SetLineColor(kBlue);
  TLegend *leg =  new TLegend(0.1,0.7,0.6,0.9,"");
  leg->AddEntry( h_YearDist,"Global dataset of victims of human trafficking","LP");
  leg->SetFillColor(10);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.037);
  //drawing hist and legend
  h_YearDist->Draw();
  leg->Draw();
}//close read
