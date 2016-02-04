#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include <vector>
#include "TCanvas.h"
using namespace std;

void Draw_pt(){
//void Eff(TString  openfile, TString outfile, TString NAME){

        TString fileMC = "newDoubleMuonTree/tnpZ_theTreeCleanedMC.root";
        TString fileData = "doubleMuonTrees/tnpZ_theTreeCleaned.root";
	TFile * fMC = new TFile("../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root");
	TFile * fData = new TFile("/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DatanoCCC.root");
	//TFile * fData = new TFile("doubleMuonTrees/tnpZ_theTreeCleaned.root");
	//TFile * fMC = new TFile(fileMC);
	//TFile * fData = new TFile(fData);
	TTree * treeMC = (TTree *)fMC->Get("tpTree/fitter_tree");
	TTree * treeData = (TTree *)fData->Get("tpTree/fitter_tree");

	//TFile * fopen = new TFile(openfile);
	//TFile* file = new TFile("pT_eff.root", "recreate");
	//TFile * fopen = new TFile("doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root");
	//TFile * fopen = new TFile("newDoubleMuonTree/TnPtreeMC.root");
	//TTree * tree1 = (TTree *)fopen->Get("tpTree/fitter_tree");
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
	treeMC->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
	treeMC->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
	treeMC->SetBranchAddress("pair_newTuneP_mass", &pair_newTuneP_mass);
	treeMC->SetBranchAddress("mass", &mass);
	treeData->SetBranchAddress("pt", &pt);
	treeData->SetBranchAddress("tag_pt", &tag_pt);
	treeData->SetBranchAddress("eta", &eta);
	treeData->SetBranchAddress("tag_eta", &tag_eta);
	treeData->SetBranchAddress("pair_pt", &pair_pt);
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
	TH1F * hpt = new TH1F("hpt","hpt", 22, 0, 220);
	TH1F * hpt_a = new TH1F("hpt_a","hpt_a", 22, 0, 220);
	TH1F * hpt_dZ = new TH1F("hpt_dZ","hpt_dZ", 22, 0, 220);
	TH1F * hptD = new TH1F("hptD","hptD", 22, 0, 220);
	TH1F * hptD_a = new TH1F("hptD_a","hptD_a", 22, 0, 220);
	TH1F * hptD_dZ = new TH1F("hptD_dZ","hptD_dZ", 22, 0, 220);
	//TH1F * hpt_eff = new TH1F("hpt_eff","hpt_eff", 30, xbins);
	//TH1F * hpt = new TH1F("hpt","hpt", 30, 0, 600);

	//Double_t pt_a[30], pt_dZ[30];
	Int_t num_pt, step, pt_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< treeMC->GetEntries(); i++){
		treeMC->GetEntry(i);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hpt_a->Fill(pair_pt);
				
		}
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hpt_dZ->Fill(pair_pt);
		}
	}
	//for(Long64_t ij=0; ij< 10000; ij++){
	for(Long64_t ij=0; ij< treeData->GetEntries(); ij++){
		treeData->GetEntry(ij);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			hptD_a->Fill(pair_pt);
				
		}
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			hptD_dZ->Fill(pair_pt);
		}
	}


	TH1F * hpt_eff = (TH1F*)hpt_dZ->Clone("hpt_eff");
	hpt_eff->Sumw2();
	hpt_eff->SetMinimum(0);
	hpt_eff->Divide(hpt_dZ, hpt_a, 1, 1, "b");
	hpt_eff->SetMaximum(1.05);
	hpt_eff->SetMinimum(0.550);
	hptD_dZ->SetMarkerColor(2);
	hptD_dZ->SetLineColor(2);
	TH1F * hptD_eff = (TH1F*)hptD_dZ->Clone("hptD_eff");
	hptD_eff->Sumw2();
	hptD_eff->SetMinimum(0);
	hptD_a->SetMarkerColor(2);
	hptD_eff->Divide(hptD_dZ, hptD_a, 1, 1, "b");
	hptD_eff->SetMaximum(1.05);
	hptD_eff->SetMinimum(0.550);


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

	//hpt->SetMarkerStyle(20);
	//hpt->SetMarkerColor(4);
	hpt_eff->SetMarkerStyle(20);
	hpt_eff->SetMarkerColor(4);
	//hpt_eff->SetMarkerErrorColor(4);
        hpt_eff->SetTitle("dZ_eff");
        hpt_eff->GetXaxis()->SetTitle("Z_pt");
        hpt_eff->GetYaxis()->SetTitle("eff_dZ");
	hpt_eff->SetStats(0);
	hpt_eff->Draw();
	hptD_eff->SetMarkerStyle(20);
	hptD_eff->SetMarkerColor(2);
	hptD_eff->Draw("same");
	//hptD_eff->Draw();


	fPads2->cd();


        TH1F * hpt_DM = (TH1F *)hptD_eff->Clone("hpt_DM");
        hpt_DM->Sumw2();
        hpt_DM->SetMinimum(0);
        hpt_DM->Divide(hptD_eff, hpt_eff, 1, 1, "b");
        hpt_DM->SetTitle("");
        hpt_DM->GetXaxis()->SetTitle("");//Z pt /GeV");
        hpt_DM->GetYaxis()->SetTitleSize(0.11);
	hpt_DM->GetYaxis()->SetTitleOffset(0.26);
        hpt_DM->GetYaxis()->SetTitle("eff Data/MC");

	hpt_DM->SetMaximum(1.5);
	hpt_DM->SetMinimum(0.5);
        hpt_DM->GetXaxis()->SetLabelSize(0.09);
        hpt_DM->GetYaxis()->SetLabelSize(0.09);
	hpt_DM->SetStats(kFALSE);
	hpt_DM->Draw();
        TLine * lineAtZero = new TLine(hpt_DM->GetXaxis()->GetXmin(), 1, hpt_DM->GetXaxis()->GetXmax(), 1);
        lineAtZero->SetLineColor(2);
        lineAtZero->SetLineStyle(2);
        lineAtZero->Draw();

	//TFile * file = new TFile(outfile, "recreate");
	//hpt_eff->Write();
	//file->Close();

	//C->SaveAs("dZ_eff_"+NAME+".pdf");
	C->SaveAs("dZ_eff_Drawpt.pdf");
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

	hpt->Draw();
	Ceff->SaveAs("dZ_pt.png");
	Ceff->SaveAs("dZ_pt.pdf");
	eff = dZbin/abin;
	cout << "eff " << eff << endl;
	*/
}


/*
void draw_pt(){
	TString filenameData = "pT_effData.root";
	TString filenameMC = "pT_effMC.root";
	TString fileMC = "newDoubleMuonTree/tnpZ_theTreeCleanedMC.root";
	TString fileData = "doubleMuonTrees/tnpZ_theTreeCleaned.root";
	//TString fileMC = "newDoubleMuonTree/TnPtreeMC.root";
	//TString fileData = "doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root";
	Eff( fileData, filenameData, "data");	
	Eff( fileMC, filenameMC, "MC");	
	
	TFile * hData = new TFile("pT_effData.root");
	TH1F * histD = (TH1F *)hData->Get("hpt_eff");
	TFile * hMC = new TFile("pT_effMC.root");
	TH1F * histM = (TH1F *)hMC->Get("hpt_eff");
	TH1F * hpt_DM = (TH1F *)histD->Clone("hpt_DM");
	hpt_DM->Sumw2();
	hpt_DM->SetMinimum(0);
	hpt_DM->Divide(histD, histM, 1, 1, "b");
	hpt_DM->SetTitle("dZ eff Data/MC");
	hpt_DM->GetXaxis()->SetTitle("Z pt /GeV");
	hpt_DM->GetYaxis()->SetTitle("eff Data/MC");

	TCanvas * C2 = new TCanvas();
	C2->Draw();
	hpt_DM->Draw("colz");
	C2->SaveAs("dZ_pt_DM.pdf");

	TCanvas * C3 = new TCanvas();
	C3->Draw();
	histD->SetMaximum(1.05);
	histD->SetMinimum(0.550);
	histD->SetLineColor(kBlue);
	histM->SetLineColor(kRed);
	
	histD->Draw();
	histM->Draw("same");

}

*/

