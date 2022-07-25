#include <iostream>
#include <iomanip>
#include <fstream>

#include "TFile.h"
#include "TString.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1F.h"
#include "TPad.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TClass.h"
#include "TLeaf.h"

using namespace std;

/// FUNCTION: GAMMA _ ENERGY PEAK_ THETA

void Theta_energy(float E_up,float E_down,TH1F* his){
  
char file_name[1000];
cout<<"Input_file_root:";cin>>file_name;

TFile *file = new TFile(file_name,"READ");
TTree *t = (TTree*)file->Get("PhaseSpace");

int nentries=t->GetEntries();
float E,dX,dY,dZ;
float theta;
char particle[1000];


t->SetBranchAddress("Ekine",&E);
t->SetBranchAddress("dX",&dX);
t->SetBranchAddress("dY",&dY);
t->SetBranchAddress("dZ",&dZ);
t->SetBranchAddress("ParticleName",&particle);


for (int i=0;i<=nentries;i++){
      t->GetEntry(i);
     if ((strcmp(particle,"gamma")==0) && (E>=E_up) && (E<E_down))
     {    
      theta=((180./3.14159)*acos(dX/sqrt(dZ*dZ+dY*dY+dX*dX)));
       his->Fill(theta);
       //cout<<theta<<endl;
      }
       
    }
     
 }

//// MAIN FUNCTION
int TTree_penergy(){
  gROOT->Reset();
  gStyle->SetOptStat("nem"); 

 /////### Input energy ###/////
float E_up,E_down;
cout<<"E_up=";cin>>E_up;
cout<<"E_down=";cin>>E_down;

/// Input the name of file root for ABS thickness//////
cout<<"The energy of proton 1"<<endl;
TH1F *his1= new TH1F ( "Theta1"," his1 ",200,-10,190);
Theta_energy(E_up,E_down,his1);

cout<<"The energy of proton 2"<<endl;
TH1F *his2= new TH1F ( "Theta2"," his2 ",200,-10,190);
Theta_energy(E_up,E_down,his2);

cout<<"The energy of proton 3"<<endl;
TH1F *his3= new TH1F ( "Theta3"," his3 ",200,-10,190);
Theta_energy(E_up,E_down,his3);

cout<<"The energy of proton 4"<<endl;
TH1F *his4= new TH1F ( "Theta4"," his4 ",200,-10,190);
Theta_energy(E_up,E_down,his4);

cout<<"The energy of proton 5"<<endl;
TH1F *his5= new TH1F ( "Theta5"," his5 ",200,-10,190);
Theta_energy(E_up,E_down,his5);

cout<<"The energy of proton 6"<<endl;
TH1F *his6= new TH1F ( "Theta6"," his6 ",200,-10,190);
Theta_energy(E_up,E_down,his6);


//// Plot histogram //////
his1->SetFillColor(2);
his1->SetLineColor(1);
his1->Draw();


his2->SetFillColor(3);
his2->SetLineColor(1);
his2->Draw("same");


his3->SetFillColor(4);
his3->SetLineColor(1);
his3->Draw("same");


his4->SetFillColor(5);
his4->SetLineColor(1);
his4->Draw("same");

his5->SetFillColor(6);
his5->SetLineColor(1);
his5->Draw("same");

his6->SetFillColor(7);
his6->SetLineColor(1);
his6->Draw("same");

//////////LEGEND///////////////

auto legend = new TLegend(0.1,0.7,0.48,0.9);
     legend->SetHeader("The Legend Title","C"); 
     legend->AddEntry(his1,"ABS: 0mm");
     legend->AddEntry(his2,"ABS: 0.5mm");
     legend->AddEntry(his3,"ABS: 0.75mm");
     legend->AddEntry(his4,"ABS: 1mm");
     legend->AddEntry(his5,"ABS: 1.25mm");
     legend->AddEntry(his6,"ABS: 1.5mm");
     legend->Draw();      



return 0;}
