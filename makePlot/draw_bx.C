#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include <vector>
#include "TCanvas.h"
#include "TLine.h"
using namespace std;

//void Eff(TString  openfile, TString outfile, TString NAME){
void draw_bx(){
	TFile * fMC = new TFile("/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_Data.root");//../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root");
        TFile * fData = new TFile("/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DataCCC.root");
        TFile * fDatano = new TFile("/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DatanoCCC.root");
        TTree * treeData = (TTree *)fMC->Get("tpTree/fitter_tree");
        TTree * treeDataCCC = (TTree *)fData->Get("tpTree/fitter_tree");
        TTree * treeDatanoCCC = (TTree *)fDatano->Get("tpTree/fitter_tree");

	//TFile * fopen2 = new TFile("newDoubleMuonTree/TnPtreeDataCCC.root");
	//TTree * tree2 = (TTree *)fopen2->Get("tpTree/fitter_tree");
	/*std::vector< TH1D* > th1fs;
	std::vector< TH1D* > th2fs;
	for ( int ij = 0; ij < 30; ++ij) {
		TString title = "mass_"; title += ij + 1; title += "_eff";
		TString title2 = "mass_dZ_"; title2 += ij + 1; title2 += "_eff";
		th1fs.push_back(new TH1D(title, title, 100, 0., 800.));
		th2fs.push_back(new TH1D(title2, title2, 100, 0., 800.));
	}*/
	Float_t pt, tag_pt, pair_pt;
	UInt_t lumi;
	Float_t tag_bx;
	UInt_t run;
	Float_t eta, tag_eta;
	Int_t DoubleIsoMu17Mu8dZ_Mu17leg;
	Int_t DoubleIsoMu17Mu8_IsoMu17leg;
	Float_t pair_newTuneP_mass;
	Float_t mass;

	treeData->SetBranchAddress("pt", &pt);
	treeData->SetBranchAddress("tag_pt", &tag_pt);
	treeData->SetBranchAddress("eta", &eta);
	treeData->SetBranchAddress("tag_eta", &tag_eta);
	treeData->SetBranchAddress("pair_pt", &pair_pt);
	treeData->SetBranchAddress("lumi", &lumi);
	treeData->SetBranchAddress("run", &run);
	treeData->SetBranchAddress("tag_bx", &tag_bx);
	treeData->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeData->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeData->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeData->SetBranchAddress("mass", &mass);
	treeDataCCC->SetBranchAddress("pt", &pt);
	treeDataCCC->SetBranchAddress("tag_pt", &tag_pt);
	treeDataCCC->SetBranchAddress("eta", &eta);
	treeDataCCC->SetBranchAddress("tag_eta", &tag_eta);
	treeDataCCC->SetBranchAddress("pair_pt", &pair_pt);
	treeDataCCC->SetBranchAddress("lumi", &lumi);
	treeDataCCC->SetBranchAddress("run", &run);
	treeDataCCC->SetBranchAddress("tag_bx", &tag_bx);
	treeDataCCC->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeDataCCC->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeDataCCC->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeDataCCC->SetBranchAddress("mass", &mass);
	treeDatanoCCC->SetBranchAddress("pt", &pt);
	treeDatanoCCC->SetBranchAddress("tag_pt", &tag_pt);
	treeDatanoCCC->SetBranchAddress("eta", &eta);
	treeDatanoCCC->SetBranchAddress("tag_eta", &tag_eta);
	treeDatanoCCC->SetBranchAddress("pair_pt", &pair_pt);
	treeDatanoCCC->SetBranchAddress("lumi", &lumi);
	treeDatanoCCC->SetBranchAddress("run", &run);
	treeDatanoCCC->SetBranchAddress("tag_bx", &tag_bx);
	treeDatanoCCC->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeDatanoCCC->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeDatanoCCC->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeDatanoCCC->SetBranchAddress("mass", &mass);
	/*
	   tree2->SetBranchAddress("pt", &pt);
	   tree2->SetBranchAddress("tag_pt", &tag_pt);
	   tree2->SetBranchAddress("eta", &eta);
	   tree2->SetBranchAddress("tag_eta", &tag_eta);
	   tree2->SetBranchAddress("pair_pt", &pair_pt);
	   tree2->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	   tree2->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	   tree2->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	   tree2->SetBranchAddress("mass", &mass);
	   */
	TH1F * hmassData = new TH1F("hmassData","hmassData", 20, 81, 101);
	TH1F * hmassDatadZ = new TH1F("hmassDatadZ","hmassDatadZ", 20, 81, 101);
	TH1F * hmass = new TH1F("hmass","hmass", 20, 81, 101);
	//Float_t xbins[31] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600};
	//Float_t xbins[11] ={0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5};
	TH1F * hbx = new TH1F("hbx","hbx", 18, 0, 3600);
	TH1F * hbx_a = new TH1F("hbx_a","hbx_a", 18, 0, 3600);
	TH1F * hbx_dZ = new TH1F("hbx_dZ","hbx_dZ", 18, 0, 3600);
	TH1F * hbxD = new TH1F("hbxD","hbxD", 18, 0, 3600);
	TH1F * hbxD_a = new TH1F("hbxD_a","hbxD_a", 18, 0, 3600);
	TH1F * hbxD_dZ = new TH1F("hbxD_dZ","hbxD_dZ", 18, 0, 3600);
	TH1F * hbxDno_a = new TH1F("hbxDno_a","hbxDno_a", 18, 0, 3600);
	TH1F * hbxDno_dZ = new TH1F("hbxDno_dZ","hbxDno_dZ", 18, 0, 3600);
	//TH1F * hbx_eff = new TH1F("hbx_eff","hbx_eff", 30, xbins);
	//TH1F * hbx = new TH1F("hbx","hbx", 30, 0, 600);

	//Double_t pt_a[30], pt_dZ[30];
	Int_t num_pt, step, pt_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< treeData->GetEntries(); i++){
		treeData->GetEntry(i);
		if(run >= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hbx_a->Fill(tag_bx);
		}
		if(run>= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hbx_dZ->Fill(tag_bx);
		}
	}
	for(Long64_t i=0; i< treeDataCCC->GetEntries(); i++){
		treeDataCCC->GetEntry(i);
		if(run >= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hbxD_a->Fill(tag_bx);
		}
		if(run>= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hbxD_dZ->Fill(tag_bx);
		}
	}
	for(Long64_t i=0; i< treeDatanoCCC->GetEntries(); i++){
		treeDatanoCCC->GetEntry(i);
		if(run >= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hbxDno_a->Fill(tag_bx);
		}
		if(run>= 259809 && run <= 259891 && pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hbxDno_dZ->Fill(tag_bx);
		}
	}


        TH1F * hbx_eff = (TH1F*)hbx_dZ->Clone("hbx_eff");
        hbx_eff->Sumw2();
        hbx_eff->SetMinimum(0);
        hbx_eff->Divide(hbx_dZ, hbx_a, 1, 1, "b");
        hbx_eff->SetMaximum(1.05);
        hbx_eff->SetMinimum(0.550);
        hbxD_dZ->SetMarkerColor(2);
        hbxD_dZ->SetLineColor(2);
        TH1F * hbxD_eff = (TH1F*)hbxD_dZ->Clone("hbxD_eff");
        hbxD_eff->Sumw2();
        hbxD_eff->SetMinimum(0);
        hbxD_a->SetMarkerColor(2);
        hbxD_eff->Divide(hbxD_dZ, hbxD_a, 1, 1, "b");
        hbxD_eff->SetMaximum(1.05);
        hbxD_eff->SetMinimum(0.550);
        TH1F * hbxDno_eff = (TH1F*)hbxDno_dZ->Clone("hbxDno_eff");
        hbxDno_eff->Sumw2();
        hbxDno_eff->SetMinimum(0);
        hbxDno_a->SetMarkerColor(1);
        hbxDno_eff->Divide(hbxDno_dZ, hbxDno_a, 1, 1, "b");
        hbxDno_eff->SetMaximum(1.05);
        hbxDno_eff->SetMinimum(0.550);


        TCanvas * C = new TCanvas();
        TPad* fPads1 = NULL;
        TPad* fPads2 = NULL;
        fPads1 = new TPad("pad1","Run2", 0.00, 0.25, 0.99, 0.99);
        fPads2 = new TPad("pad2","", 0.00, 0.05, 0.99, 0.25);
        fPads1->SetFillColor(0);
        fPads1->SetLineColor(0);
        fPads2->SetFillColor(0);
        fPads2->SetFillColor(0);
        fPads1->Draw();
        fPads2->Draw();

        fPads1->cd();
        hbx_eff->SetMarkerStyle(20);
        hbx_eff->SetMarkerColor(4);
        hbx_eff->SetTitle("dZ_eff");
        hbx_eff->GetXaxis()->SetTitle("bx");
        hbx_eff->GetYaxis()->SetTitle("eff_dZ");
        hbx_eff->SetStats(0);
        hbx_eff->Draw();
        hbxD_eff->SetMarkerStyle(20);
        hbxD_eff->SetMarkerColor(2);
        hbxD_eff->Draw("same");
        hbxDno_eff->SetMarkerStyle(20);
        hbxDno_eff->SetMarkerColor(1);
        hbxDno_eff->SetLineColor(1);
        hbxDno_eff->Draw("same");
        TLegend *leg = new TLegend(0.13, 0.18, 0.38, 0.38);
        leg->AddEntry(hbx_eff, "data with loose CCC", "f");
        leg->AddEntry(hbxD_eff, "data with tiny CCC", "f");
        leg->AddEntry(hbxDno_eff, "data with no CCC", "f");
        leg->Draw();

        fPads2->cd();


        TH1F * hbx_DM = (TH1F *)hbxD_eff->Clone("hbx_DM");
        hbx_DM->Sumw2();
        hbx_DM->SetMinimum(0);
        hbx_DM->Divide(hbxD_eff, hbx_eff, 1, 1, "b");
        hbx_DM->SetTitle("");
        hbx_DM->GetXaxis()->SetTitle("");//Z pt /GeV");
        hbx_DM->GetYaxis()->SetTitleSize(0.11);
        hbx_DM->GetYaxis()->SetTitleOffset(0.26);
        hbx_DM->GetYaxis()->SetTitle("ratio");

        hbx_DM->SetMaximum(1.15);
        hbx_DM->SetMinimum(0.85);
        hbx_DM->SetStats(kFALSE);
	hbx_DM->SetLabelSize(0.09);
	hbx_DM->GetYaxis()->SetLabelSize(0.09);
        hbx_DM->Draw();
        TH1F * hbx_DMno = (TH1F *)hbxDno_eff->Clone("hbx_DMno");
        hbx_DMno->Sumw2();
        hbx_DMno->SetMinimum(0);
        hbx_DMno->Divide(hbxDno_eff, hbx_eff, 1, 1, "b");
	hbx_DMno->Draw("same");
        TH1F * hbx_DMN = (TH1F *)hbxDno_eff->Clone("hbx_DMN");
        hbx_DMN->Sumw2();
        hbx_DMN->SetMinimum(0);
        hbx_DMN->Divide(hbxDno_eff, hbxD_eff, 1, 1, "b");
	hbx_DMN->SetLineColor(3);
	hbx_DMN->SetMarkerColor(3);
	hbx_DMN->Draw("same");
        fPads2->Update();

/*        TLegend *leg_2 = new TLegend(0.13, 0.05, 0.40, 0.45);
        leg_2->AddEntry(hbx_DM, "tiny/loose", "f");
        leg_2->AddEntry(hbx_DMno, "no/loose", "f");
        leg_2->AddEntry(hbx_DMN, "no/loose", "f");
        leg_2->Draw();
*/
	TLine * lineAtZero = new TLine(0, 1.0, 3600, 1.0);
	//TLine * lineAtZero = new TLine(hbx_DM->GetXaxis()->GetXmin(), 0, hbx_DM->GetXaxis()->GetXmax(), 0);
	lineAtZero->SetLineColor(2);
	lineAtZero->SetLineStyle(2);
	lineAtZero->Draw();


        C->SaveAs("dZ_bx_check.pdf");

	//C->SaveAs("dZ_eff_MC.png");
	/*
	   TCanvas *Ceff = new TCanvas();
	   Ceff->Draw();
	   Double_t abin, dZbin, eff;
	   for(int ibin=0; ibin<20; ibin++){
	   abin = abin + hmassData->GetBinContent(ibin);
	   dZbin = dZbin + hmassDatadZ->GetBinContent(ibin);
	//eff = bbin/abin;
	//hmass->SetBinContent(ibin,eff);

	}

	hbx->Draw();
	Ceff->SaveAs("dZ_pt.png");
	Ceff->SaveAs("dZ_pt.pdf");
	eff = dZbin/abin;
	cout << "eff " << eff << endl;
	*/
}

