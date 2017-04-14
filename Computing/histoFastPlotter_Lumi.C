#include "TChain.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"

/*
void histoFastPlotter(){

//TFile * fopen = new TFile("/tmp/quwang/TnPTree_80X_Run2016Cv2_GoldenJSON.root");
//TChain *chain = new TChain("tpTree/fitter_tree");
TChain *chain =  new TChain("tpTree/fitter_tree");
TFile *myOuputFile = new TFile("theOutputFile.root","RECREATE");


}

void drawAPlot(TString nameVar, TString nameHisto, TString cuts, int bins, float min, float max){
    TH1F *theHisto = new TH1F(nameHisto, nameHisto, bins, min, max);
    chain->Draw(nameVar+">>"+nameHisto, cuts);
    myOuputFile->ls();
    theHisto->Write(nameHisto);
    delete theHisto;
}

void drawAPlot2D(TString nameVarX, TString nameVarY, TString nameHisto, TString cuts, int Xbins, float Xmin, float Xmax, int Ybins, float Ymin, float Ymax){
    TH2F *theHisto = new TH2F(nameHisto, nameHisto, Xbins, Xmin, Xmax, Ybins, Ymin, Ymax);
    chain->Draw(nameVarY+":"+nameVarX+">>"+nameHisto, cuts);
    myOuputFile->ls();
    theHisto->Write(nameHisto);
    delete theHisto;
}

void drawAPlot2DMovingBins(TString nameVarX, TString nameVarY, TString nameHisto, TString cuts, int nbXbin, float *binX, int nbYbin, float *binY){
    TH2F *theHisto = new TH2F(nameHisto, nameHisto, nbXbin, binX, nbYbin, binY);
    chain->Draw(nameVarY+":"+nameVarX+">>"+nameHisto, cuts);
    myOuputFile->ls();
    theHisto->Write(nameHisto);
    delete theHisto;
 
}

*/
//void checkBinMigration(){
void histoFastPlotter_Lumi(){
    TChain *chain =  new TChain("tpTree/fitter_tree");
    TFile *myOuputFile = new TFile("theOutputFile_BCDv2_testreweight.root","RECREATE");
    //chain->Add("/tmp/quwang/TnPTree_80X_Run2016Cv2_GoldenJSON.root");
    chain->Add("/tmp/quwang/TnPTree_80X_Run2016_BCD.root");
    //TH1F *theHisto = new TH1F(nameHisto, nameHisto, bins, min, max);
    //chain->Draw(nameVar+">>"+nameHisto, cuts);    
    TH1F *theHisto = new TH1F("h1_tag_IsoMu22", "h1_tag_IsoMu22", 50, 2000, 12000);
    TH1F *theHisto2 = new TH1F("h1_tag_IsoMu22Mu17", "h1_tag_IsoMu22Mu17", 50, 2000, 12000);
    chain->Draw("tag_instLumi>>h1_tag_IsoMu22", "pt>23 && tag_pt>23 && abseta<=2.4 && tag_abseta<=2.4 && tag_IsoMu22>0");    
    chain->Draw("tag_instLumi>>h1_tag_IsoMu22Mu17", "pt>23 && tag_pt>23 && abseta<=2.4 && tag_abseta<=2.4 && tag_IsoMu22>0 && tag_Mu17>0");    
	
    theHisto->SetTitle("instLumi of tag_IsoMu22");
    theHisto->GetXaxis()->SetTitle("instLumi");
    theHisto->GetYaxis()->SetTitle("events");

    theHisto2->SetTitle("instLumi of tag_IsoMu22&&tag_Mu17");
    theHisto2->GetXaxis()->SetTitle("instLumi");
    theHisto2->GetYaxis()->SetTitle("events");

    TH1F * theRatio = (TH1F*)theHisto->Clone("theRatio");
    theRatio->Sumw2();
    double num1 = theRatio->Integral();
    double num2 = theHisto2->Integral();
    theRatio->Divide(theHisto, theHisto2, 1./num1, 1./num2);
    theRatio->SetTitle("instLumi reweight");
    theRatio->GetXaxis()->SetTitle("instLumi");
    theRatio->GetYaxis()->SetTitle("Mu22/ Mu22&&Mu17");

    TH1F * theRatio_b = (TH1F*)theHisto->Clone("theRatio_b");
    theRatio_b->Sumw2();
    theRatio_b->Divide(theHisto, theHisto2, 1./num1, 1./num2, "b");
    theRatio_b->SetTitle("instLumi reweight");
    theRatio_b->GetXaxis()->SetTitle("instLumi");
    theRatio_b->GetYaxis()->SetTitle("Mu22/ Mu22&&Mu17");

    theHisto->Write();
    theHisto2->Write();
    theRatio->Write();
    theRatio_b->Write();

    TCanvas * c1 = new TCanvas();
    TCanvas * c2 = new TCanvas();
    TCanvas * c3 = new TCanvas();
    TCanvas * c4 = new TCanvas();

    c1->cd();
    theHisto->Draw();    
    c1->SaveAs("instLumi_Mu22_v2.pdf");
    
    c2->cd();
    theHisto2->Draw();    
    c2->SaveAs("instLumi_Mu22M17_v2.pdf");

    c3->cd();
    theRatio->Draw();    
    c3->SaveAs("instLumi_ratio_v2.pdf");

    c4->cd();
    theRatio_b->Draw();    
    c4->SaveAs("instLumi_ratioB_v2.pdf");


}
