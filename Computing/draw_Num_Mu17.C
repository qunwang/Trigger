#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH2F.h"


//void draw_Num_Mu17(){
//void draw_Num(TString  TRIGGER){
void draw_Num(TString  TRIGGER, TString TRIGGER2, TString TRIGGER3){

    TFile * fopen = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_eff_Mu17Mu8Clean_ICHEP_runBCDdoub22.root");
    //TFile * fopen = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_eff_Mu17Mu8Clean.root");
    TTree *tIn = (TTree *)fopen->Get("tpTree/fitter_tree");
    
    Float_t pt, abseta, tag_pt, tag_abseta;
    Int_t Mu17Eff,EffMu17Mu8, EffMu17TkMu8, pathOr, pathOrMu20, EffMu17Mu8nodz, EffMu17TkMu8nodz, pathOrnodz;
    Int_t tag_IsoMu20, IsoMu20, tag_IsoTkMu20, IsoTkMu20 ;
    Int_t tag_DoubleIsoMu17TkMu8_IsoMu17leg, DoubleIsoMu17TkMu8_IsoMu8leg, DoubleIsoMu17TkMu8_IsoMu17leg, tag_DoubleIsoMu17TkMu8_IsoMu8leg;
    Int_t tag_DoubleIsoMu17Mu8_IsoMu17leg, DoubleIsoMu17Mu8_IsoMu8leg, DoubleIsoMu17Mu8_IsoMu17leg, tag_DoubleIsoMu17Mu8_IsoMu8leg;
    Int_t Mu17, tag_Mu17;
    Int_t Tight2012, tag_Tight2012;
    Float_t combRelIsoPF04dBeta, tag_combRelIsoPF04dBeta;
    ULong64_t event;
    UInt_t run;
    Float_t mass;

    tIn->SetBranchAddress("pt", &pt);
    tIn->SetBranchAddress("run", &run);
    tIn->SetBranchAddress("mass", &mass);
    tIn->SetBranchAddress("abseta", &abseta);
    tIn->SetBranchAddress("tag_pt", &tag_pt);
    tIn->SetBranchAddress("tag_abseta", &tag_abseta);
    tIn->SetBranchAddress("event", &event);

    tIn->SetBranchAddress("tag_IsoTkMu20", &tag_IsoTkMu20);
    tIn->SetBranchAddress("IsoTkMu20", &IsoTkMu20);

    tIn->SetBranchAddress("tag_IsoMu20", &tag_IsoMu20);
    tIn->SetBranchAddress("IsoMu20", &IsoMu20);


/////////////////////leg with Iso  9 lines below is new for 8X
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu17leg", &tag_DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu8leg", &DoubleIsoMu17Mu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu8leg", &tag_DoubleIsoMu17Mu8_IsoMu8leg);

    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu17leg", &DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu17leg", &tag_DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu8leg", &tag_DoubleIsoMu17TkMu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu8leg", &DoubleIsoMu17TkMu8_IsoMu8leg);


    tIn->SetBranchAddress("Mu17", &Mu17);
    tIn->SetBranchAddress("tag_Mu17", &tag_Mu17);
    tIn->SetBranchAddress("Mu17Eff", &Mu17Eff);
    tIn->SetBranchAddress("Tight2012", &Tight2012);
    tIn->SetBranchAddress("tag_Tight2012", &tag_Tight2012);
    tIn->SetBranchAddress("combRelIsoPF04dBeta", &combRelIsoPF04dBeta);
    tIn->SetBranchAddress("tag_combRelIsoPF04dBeta", &tag_combRelIsoPF04dBeta);

    Int_t nbins = 4;
    Double_t Bin[5] = {0., 0.9, 1.2, 2.2, 2.4};
    TH2F * h2_Mu17Mu8 = new TH2F("h2_Mu17Mu8", "h2_Mu17Mu8", nbins, Bin, nbins, Bin);
    TH2F * h2_Mu17TkMu8 = new TH2F("h2_Mu17TkMu8", "h2_Mu17TkMu8", nbins, Bin, nbins, Bin);
    TH2F * h2_orPath = new TH2F("h2_orPath", "h2_orPath", nbins, Bin, nbins, Bin);
    TH2F * h2_Mu17 = new TH2F("h2_Mu17", "h2_Mu17", nbins, Bin, nbins, Bin);
    TH2F * h2_Mu17Mu17 = new TH2F("h2_Mu17Mu17", "h2_Mu17Mu17", nbins, Bin, nbins, Bin);
    h2_Mu17Mu8->Sumw2();
    h2_Mu17TkMu8->Sumw2();
    h2_orPath->Sumw2();
    h2_Mu17->Sumw2();
    h2_Mu17Mu17->Sumw2();

    TCanvas * c1 = new TCanvas();
    TCanvas * c2 = new TCanvas();
    TCanvas * c3 = new TCanvas();
    TCanvas * c4 = new TCanvas();
    TCanvas * c5 = new TCanvas();
    for(Int_t i = 0, n = tIn->GetEntries(); i < n ; i++){
	tIn->GetEntry(i);
//----------------------no dz -----------------------------
        EffMu17Mu8nodz = 0;
        if((tag_DoubleIsoMu17Mu8_IsoMu17leg&&DoubleIsoMu17Mu8_IsoMu8leg)||(DoubleIsoMu17Mu8_IsoMu17leg&&tag_DoubleIsoMu17Mu8_IsoMu8leg))
        EffMu17Mu8nodz = 1;
    
        EffMu17TkMu8nodz = 0;
        if((tag_DoubleIsoMu17TkMu8_IsoMu17leg&&DoubleIsoMu17TkMu8_IsoMu8leg)||(DoubleIsoMu17TkMu8_IsoMu17leg&&tag_DoubleIsoMu17TkMu8_IsoMu8leg))
        EffMu17TkMu8nodz = 1;
    
        pathOrnodz=0;
        if(EffMu17Mu8nodz||EffMu17TkMu8nodz)
        pathOrnodz=1;
//-----------------------------------------------------------------------
	//if(Mu17Eff>=0 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && TRIGGER>0)
	if(Mu17Eff>0 && mass>76 && mass<125 && run>274094 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && combRelIsoPF04dBeta<0.25 && tag_combRelIsoPF04dBeta<0.25 && combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta>-0.5 && EffMu17Mu8nodz>0)
	h2_Mu17Mu8->Fill(abseta, tag_abseta);

	//if(Mu17Eff>=0 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && TRIGGER2>0)
	if(Mu17Eff>0 && mass>76 && mass<125 && run>274094 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && combRelIsoPF04dBeta<0.25 && tag_combRelIsoPF04dBeta<0.25 && combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta>-0.5 && EffMu17TkMu8nodz>0)
	h2_Mu17TkMu8->Fill(abseta, tag_abseta);

	//if(Mu17Eff>=0 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && TRIGGER3>0)
	if(Mu17Eff>0 && mass>76 && mass<125 && run>274094 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && combRelIsoPF04dBeta<0.25 && tag_combRelIsoPF04dBeta<0.25 && combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta>-0.5  && pathOrnodz>0)
	h2_orPath->Fill(abseta, tag_abseta);
	if(Mu17Eff>0 && mass>76 && mass<125 && run>274094 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && combRelIsoPF04dBeta<0.25 && tag_combRelIsoPF04dBeta<0.25 && combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta>-0.5)
	h2_Mu17->Fill(abseta, tag_abseta);
	if(Mu17Eff>0 && mass>76 && mass<125 && run>274094 && Mu17>0 && tag_Mu17>0 && pt>20 && tag_pt>20 && Tight2012>0 && tag_Tight2012>0 && abseta<=2.4 && tag_abseta<=2.4 && combRelIsoPF04dBeta<0.25 && tag_combRelIsoPF04dBeta<0.25 && combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta>-0.5)
	h2_Mu17Mu17->Fill(abseta, tag_abseta);

    }
    c1->cd();
    h2_Mu17Mu8->SetStats(0);
    h2_Mu17Mu8->Divide(h2_Mu17);
    h2_Mu17Mu8->Draw("colz:text");
    c1->SaveAs("Mu17_num"+TRIGGER+".pdf");
    c1->SaveAs("Mu17_num"+TRIGGER+".png");

    c2->cd();
    h2_Mu17TkMu8->SetStats(0);
    h2_Mu17TkMu8->Divide(h2_Mu17);
    h2_Mu17TkMu8->Draw("colz:text");
    c2->SaveAs("Mu17_num"+TRIGGER2+".pdf");
    c2->SaveAs("Mu17_num"+TRIGGER2+".png");

    c3->cd();
    h2_orPath->SetStats(0);
    h2_orPath->Divide(h2_Mu17);
    h2_orPath->Draw("colz:text");
    c3->SaveAs("Mu17_num"+TRIGGER3+".pdf");
    c3->SaveAs("Mu17_num"+TRIGGER3+".png");

    c4->cd();
    h2_Mu17->SetStats(0);
    h2_Mu17->Draw("colz:text");
    c4->SaveAs("Mu17_num.pdf");

    c5->cd();
    h2_Mu17Mu17->SetStats(0);
    h2_Mu17Mu17->Divide(h2_Mu17);
    h2_Mu17Mu17->Draw("colz:text");
    c5->SaveAs("Mu17_numMu17Mu17.pdf");
    c5->SaveAs("Mu17_numMu17Mu17.png");

}

void draw_Num_Mu17(){

    draw_Num("EffMu17Mu8nodz", "EffMu17TkMu8nodz", "pathOrnodz");
    //draw_Num("EffMu17Mu8nodz");
    //draw_Num("EffMu17TkMu8nodz");
    //draw_Num("pathOrnodz");

}








