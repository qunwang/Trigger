#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include <vector>
#include "TCanvas.h"
using namespace std;

void Eff(TString  openfile, TString outfile, TString NAME){

	TFile * fopen = new TFile(openfile);
	//TFile* file = new TFile("pT_eff.root", "recreate");
	//TFile * fopen = new TFile("doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root");
	//TFile * fopen = new TFile("newDoubleMuonTree/TnPtreeMC.root");
	TTree * tree1 = (TTree *)fopen->Get("tpTree/fitter_tree");
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
	Float_t tag_instLumi;
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
	tree1->SetBranchAddress("tag_instLumi", &tag_instLumi);
	tree1->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	tree1->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	tree1->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	tree1->SetBranchAddress("mass", &mass);
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
	TH1F * hlumi = new TH1F("hlumi","hlumi", 60, 0, 6000);
	TH1F * hlumi_a = new TH1F("hlumi_a","hlumi_a", 60, 0, 6000);
	TH1F * hlumi_dZ = new TH1F("hlumi_dZ","hlumi_dZ", 60, 0, 6000);
	//TH1F * hlumi_eff = new TH1F("hlumi_eff","hlumi_eff", 30, xbins);
	//TH1F * hlumi = new TH1F("hlumi","hlumi", 30, 0, 600);

	//Double_t pt_a[30], pt_dZ[30];
	Int_t num_pt, step, pt_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< tree1->GetEntries(); i++){
		tree1->GetEntry(i);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hlumi_a->Fill(tag_instLumi);
			//hlumi_a->Fill(pair_pt);
				
		}
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hlumi_dZ->Fill(tag_instLumi);
			//hlumi_dZ->Fill(pair_pt);
		}
	}


	TH1F * hlumi_eff = (TH1F*)hlumi_dZ->Clone("hlumi_eff");
	hlumi_eff->Sumw2();
	hlumi_eff->SetMinimum(0);
	//hlumi_eff->GetYaxis()->RangeUser();
	hlumi_eff->Divide(hlumi_dZ, hlumi_a, 1, 1, "b");
	//cout << "eff_test" << eff_test << endl;
	TCanvas * C = new TCanvas();
	C->Draw();
	//hlumi->SetMarkerStyle(20);
	//hlumi->SetMarkerColor(4);
	hlumi_eff->SetMarkerStyle(20);
	hlumi_eff->SetMarkerColor(4);
        hlumi_eff->SetTitle("dZ_eff_"+NAME);
        hlumi_eff->GetXaxis()->SetTitle("lumi");
        hlumi_eff->GetYaxis()->SetTitle("eff_dZ");
	hlumi_eff->SetStats(0);
	hlumi_eff->Draw();

	TFile * file = new TFile(outfile, "recreate");
	hlumi_eff->Write();
	file->Close();

	C->SaveAs("dZ_eff_"+NAME+".pdf");
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

	hlumi->Draw();
	Ceff->SaveAs("dZ_pt.png");
	Ceff->SaveAs("dZ_pt.pdf");
	eff = dZbin/abin;
	cout << "eff " << eff << endl;
	*/
}

void draw_lumi(){
	TString filenameData = "lumi_effData.root";
	TString filenameMC = "lumi_effMC.root";
	TString fileMC = "../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root";
	//TString fileData = "doubleMuonTrees/tnpZ_theTreeCleaned.root";
        TString fileData = "/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_Data.root";//"doubleMuonTrees/tnpZ_theTreeCleaned.root";

	//TString fileMC = "newDoubleMuonTree/TnPtreeMC.root";
	//TString fileData = "doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root";
	Eff( fileData, filenameData, "data_lumi");	
	//Eff( fileMC, filenameMC, "MC_lumi");	
	
	TFile * hData = new TFile("lumi_effData.root");
	TH1F * histD = (TH1F *)hData->Get("hlumi_eff");
	TFile * hMC = new TFile("lumi_effMC.root");
	TH1F * histM = (TH1F *)hMC->Get("hlumi_eff");
	TH1F * hlumi_DM = (TH1F *)histD->Clone("hlumi_DM");
	hlumi_DM->Sumw2();
	hlumi_DM->SetMinimum(0);
	hlumi_DM->Divide(histD, histM, 1, 1, "b");
	hlumi_DM->SetTitle("dZ eff Data/MC");
	hlumi_DM->GetXaxis()->SetTitle("lumi");
	hlumi_DM->GetYaxis()->SetTitle("eff Data/MC");

	TCanvas * C2 = new TCanvas();
	C2->Draw();
	hlumi_DM->Draw("colz");
	//C2->SaveAs("dZ_lumi_DM.pdf");

}



