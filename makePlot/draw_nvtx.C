#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include <vector>
#include "TCanvas.h"
using namespace std;

void draw_nvtx(){
        TFile * fMC = new TFile("../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root");
        TFile * fData = new TFile("/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DatanoCCC.root");
        TTree * treeMC = (TTree *)fMC->Get("tpTree/fitter_tree");
        TTree * treeData = (TTree *)fData->Get("tpTree/fitter_tree");

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

	treeMC->SetBranchAddress("pt", &pt);
	treeMC->SetBranchAddress("tag_pt", &tag_pt);
	treeMC->SetBranchAddress("eta", &eta);
	treeMC->SetBranchAddress("tag_eta", &tag_eta);
	treeMC->SetBranchAddress("pair_pt", &pair_pt);
	treeMC->SetBranchAddress("tag_nVertices", &tag_nVertices);
	treeMC->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeMC->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeMC->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeMC->SetBranchAddress("mass", &mass);
	treeData->SetBranchAddress("pt", &pt);
	treeData->SetBranchAddress("tag_pt", &tag_pt);
	treeData->SetBranchAddress("eta", &eta);
	treeData->SetBranchAddress("tag_eta", &tag_eta);
	treeData->SetBranchAddress("pair_pt", &pair_pt);
	treeData->SetBranchAddress("tag_nVertices", &tag_nVertices);
	treeData->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeData->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeData->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeData->SetBranchAddress("mass", &mass);
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
	TH1F * hnvtxD = new TH1F("hnvtxD","hnvtxD", 30, 0, 30);
	TH1F * hnvtxD_a = new TH1F("hnvtxD_a","hnvtxD_a", 30, 0, 30);
	TH1F * hnvtxD_dZ = new TH1F("hnvtxD_dZ","hnvtxD_dZ", 30, 0, 30);

	//Double_t pt_a[30], pt_dZ[30];
	Int_t num_pt, step, pt_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< treeMC->GetEntries(); i++){
		treeMC->GetEntry(i);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hnvtx_a->Fill(tag_nVertices);
				
		}
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hnvtx_dZ->Fill(tag_nVertices);
		}
	}
	for(Long64_t i=0; i< treeData->GetEntries(); i++){
		treeData->GetEntry(i);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hnvtxD_a->Fill(tag_nVertices);
				
		}
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hnvtxD_dZ->Fill(tag_nVertices);
		}
	}


	TH1F * hnvtx_eff = (TH1F*)hnvtx_dZ->Clone("hnvtx_eff");
	hnvtx_eff->Sumw2();
	hnvtx_eff->Divide(hnvtx_dZ, hnvtx_a, 1, 1, "b");
	hnvtx_eff->SetMarkerStyle(20);
	hnvtx_eff->SetMarkerColor(4);
	hnvtx_eff->SetLineColor(4);
        hnvtx_eff->SetTitle("dZ_eff_MC");
        hnvtx_eff->GetXaxis()->SetTitle("tag_nVertices");
        hnvtx_eff->GetYaxis()->SetTitle("eff_dZ");
	hnvtx_eff->SetStats(0);
	hnvtx_eff->SetMinimum(0.5000);
	hnvtx_eff->SetMaximum(1.05);
	//hnvtx_eff->Draw();
        TH1F * hnvtxD_eff = (TH1F*)hnvtxD_dZ->Clone("hnvtxD_eff");
        hnvtxD_eff->Sumw2();
        hnvtxD_eff->SetMinimum(0);
        hnvtxD_a->SetMarkerColor(2);
        hnvtxD_a->SetLineColor(2);
        hnvtxD_eff->Divide(hnvtxD_dZ, hnvtxD_a, 1, 1, "b");
        hnvtxD_eff->SetMaximum(1.05);
        hnvtxD_eff->SetMinimum(0.550);

        TCanvas * C = new TCanvas();
        TPad* fPads1 = NULL;
        TPad* fPads2 = NULL;
        fPads1 = new TPad("pad1","Run2", 0.00, 0.25, 0.99, 0.99);
        fPads2 = new TPad("pad2","", 0.00, 0.00, 0.99, 0.25);
        fPads1->SetFillColor(0);
        fPads1->SetLineColor(0);
        fPads2->SetFillColor(0);
        fPads2->SetFillColor(0);
        fPads1->Draw();
        fPads2->Draw();

        fPads1->cd();
        hnvtx_eff->SetMarkerStyle(20);
        hnvtx_eff->SetMarkerColor(4);
        hnvtx_eff->SetLineColor(4);
        hnvtx_eff->SetTitle("dZ_eff");
        hnvtx_eff->GetXaxis()->SetTitle("tag_nVertices");
        hnvtx_eff->GetYaxis()->SetTitle("eff_dZ");
        hnvtx_eff->SetStats(0);
        hnvtx_eff->Draw();
        hnvtxD_eff->SetMarkerStyle(20);
        hnvtxD_eff->SetMarkerColor(2);
        hnvtxD_eff->SetLineColor(2);
        hnvtxD_eff->Draw("same");
        fPads2->cd();


        TH1F * hnvtx_DM = (TH1F *)hnvtxD_eff->Clone("hnvtx_DM");
        hnvtx_DM->Sumw2();
        hnvtx_DM->SetMinimum(0);
        hnvtx_DM->Divide(hnvtxD_eff, hnvtx_eff, 1, 1, "b");
        hnvtx_DM->SetTitle("");
        hnvtx_DM->GetXaxis()->SetTitle("");//Z pt /GeV");
        hnvtx_DM->GetYaxis()->SetTitleSize(0.11);
        hnvtx_DM->GetYaxis()->SetTitleOffset(0.26);
        hnvtx_DM->GetYaxis()->SetTitle("eff Data/MC");

        hnvtx_DM->SetMaximum(1.5);
        hnvtx_DM->SetMinimum(0.5);
        hnvtx_DM->SetStats(kFALSE);
        hnvtx_DM->GetXaxis()->SetLabelSize(0.09);
        hnvtx_DM->GetYaxis()->SetLabelSize(0.09);
        hnvtx_DM->Draw();
        TLine * lineAtZero = new TLine(hnvtx_DM->GetXaxis()->GetXmin(), 1, hnvtx_DM->GetXaxis()->GetXmax(), 1);
        lineAtZero->SetLineColor(2);
        lineAtZero->SetLineStyle(2);
        lineAtZero->Draw();

        C->SaveAs("dZ_eff_Drawnvtx.pdf");

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




