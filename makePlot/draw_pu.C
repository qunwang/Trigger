#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include <vector>
#include "TCanvas.h"
using namespace std;

void draw_pu(){
        TString fileMC = "../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root";
        TString fileData = "/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DatanoCCC.root";//doubleMuonTrees/tnpZ_theTreeCleaned.root";
	TFile * fopen = new TFile(fileData);
	TTree * tree1 = (TTree *)fopen->Get("tpTree/fitter_tree");
	TFile * fopen2 = new TFile(fileMC);
	TTree * tree2 = (TTree *)fopen2->Get("tpTree/fitter_tree");
	//TFile * fopen2 = new TFile("newDoubleMuonTree/TnPtreeMC.root");
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
	Float_t tag_nVertices;
	Float_t eta, tag_eta;
	Int_t DoubleIsoMu17Mu8dZ_Mu17leg;
	Int_t DoubleIsoMu17Mu8_IsoMu17leg;
	Float_t pair_newTuneP_mass;
	Float_t mass;

	tree1->SetBranchAddress("pt", &pt);
	tree1->SetBranchAddress("tag_pt", &tag_pt);
	tree1->SetBranchAddress("eta", &eta);
	tree1->SetBranchAddress("tag_eta", &tag_eta);
	tree1->SetBranchAddress("pair_pt", &pair_pt);
	tree1->SetBranchAddress("tag_nVertices", &tag_nVertices);
	tree1->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	tree1->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	tree1->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	tree1->SetBranchAddress("mass", &mass);
	tree2->SetBranchAddress("pt", &pt);
	tree2->SetBranchAddress("tag_pt", &tag_pt);
	tree2->SetBranchAddress("eta", &eta);
	tree2->SetBranchAddress("tag_eta", &tag_eta);
	tree2->SetBranchAddress("pair_pt", &pair_pt);
	tree2->SetBranchAddress("tag_nVertices", &tag_nVertices);
	tree2->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	tree2->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	tree2->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	tree2->SetBranchAddress("mass", &mass);
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
	TH1F * hnvtx = new TH1F("hnvtx","hnvtx", 30, 0, 30);
	TH1F * hnvtx_a = new TH1F("hnvtx_a","hnvtx_a", 30, 0, 30);
	TH1F * hnvtx_dZ = new TH1F("hnvtx_dZ","hnvtx_dZ", 30, 0, 30);
	//TH1F * hnvtx_eff = new TH1F("hnvtx_eff","hnvtx_eff", 30, xbins);
	//TH1F * hnvtx = new TH1F("hnvtx","hnvtx", 30, 0, 600);

	//Double_t pt_a[30], pt_dZ[30];
	Int_t num_pt, step, pt_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< tree1->GetEntries(); i++){
		tree1->GetEntry(i);
		//if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hnvtx_a->Fill(tag_nVertices);
			//hnvtx_a->Fill(pair_pt);
				
		//}
	}
        for(Long64_t i=0; i< tree2->GetEntries(); i++){
                tree2->GetEntry(i);
		hnvtx_dZ->Fill(tag_nVertices);
	}

	//hnvtx_eff->GetYaxis()->RangeUser();
	//cout << "eff_test" << eff_test << endl;
	TCanvas * C = new TCanvas();
	C->Draw();
	//hnvtx->SetMarkerStyle(20);
	//hnvtx->SetMarkerColor(4);
	//hnvtx_a->SetMarkerStyle(20);
	//hnvtx_a->SetMarkerColor(4);
	hnvtx_a->SetLineColor(kBlue);
	hnvtx_dZ->SetLineColor(kRed);
		
        hnvtx_a->SetTitle("tag_nVertices distribution");
        hnvtx_a->GetXaxis()->SetTitle("tag_nVertices");
        hnvtx_a->GetYaxis()->SetTitle("number");
	hnvtx_a->SetStats(0);
	hnvtx_a->Draw();
	hnvtx_dZ->Draw("same");
	TLegend *leg = new TLegend(0.78, 0.78, 0.88, 0.88);
	leg->AddEntry(hnvtx_a, "data with no CCC", "f");
	leg->AddEntry(hnvtx_dZ, "MC", "f");
	leg->Draw();
	C->SaveAs("dZ_tag_nVertices.pdf");
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

	hnvtx->Draw();
	Ceff->SaveAs("dZ_pt.png");
	Ceff->SaveAs("dZ_pt.pdf");
	eff = dZbin/abin;
	cout << "eff " << eff << endl;
	*/
}


