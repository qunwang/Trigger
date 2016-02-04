#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2D.h"
#include <vector>
#include "TCanvas.h"
using namespace std;

void Eff(TString  openfile, TString outfile, TString NAME){
//void draw_eta(){

        TFile * fopen = new TFile(openfile);
	//TFile * fopen = new TFile("doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root");
	//TFile * fopen = new TFile("newDoubleMuonTree/TnPtreeMC.root");
	TTree * tree1 = (TTree *)fopen->Get("tpTree/fitter_tree");
	//TFile * fopen2 = new TFile("newDoubleMuonTree/TnPtreeMC.root");
	//TTree * tree2 = (TTree *)fopen2->Get("tpTree/fitter_tree");
	std::vector< TH1D* > th1fs;
	std::vector< TH1D* > th2fs;
	std::vector< TH1D* > th3fs;
	std::vector< TH1D* > th4fs;
	for ( int ij = 0; ij < 4; ++ij) {
		TString title = "mass_"; title += ij + 1; title += "_eff";
		TString title2 = "mass_dZ_"; title2 += ij + 1; title2 += "_eff";
		TString title3 = "mass2__"; title3 += ij + 1; title3 += "_eff";
		TString title4 = "mass2_dZ_"; title4 += ij + 1; title4 += "_eff";
		th1fs.push_back(new TH1D(title, title, 100, 0., 800.));
		th2fs.push_back(new TH1D(title2, title2, 100, 0., 800.));
		th3fs.push_back(new TH1D(title3, title3, 100, 0., 800.));
		th4fs.push_back(new TH1D(title4, title4, 100, 0., 800.));
	}
	Float_t pt, tag_pt, pair_pt;
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
	TH1F * hmass = new TH1F("hmass","hmass", 20, 81, 101);
	Float_t xbins[5] = { 0., 0.9, 1.2, 2.1, 2.4};
	//Float_t xbins[31] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600};
	TH2D * heta_a = new TH2D("heta_a","heta_a", 4, xbins, 4, xbins);
	TH2D * heta_dZ = new TH2D("heta_dZ","heta_dZ", 4, xbins, 4, xbins);
	//TH1F * hpt = new TH1F("hpt","hpt", 22, 0, 220);
	//TH1F * hpt_a = new TH1F("hpt_a","hpt_a", 22, 0, 220);
	//TH1F * hpt_dZ = new TH1F("hpt_dZ","hpt_dZ", 22, 0, 220);

	Int_t num_eta, step, eta_cut;

	//for(Long64_t i=0; i< 10000; i++){
	for(Long64_t i=0; i< tree1->GetEntries(); i++){
		tree1->GetEntry(i);
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8_IsoMu17leg>0 && mass> 81 && mass<101){
			heta_a->Fill(eta, tag_eta);
			//for( num_eta=0 ; num_eta<4; num_eta++){
				//if(fabs(eta)< xbins[num_eta] && fabs(eta)< xbins[num_eta+1]) {th1fs[num_eta]->Fill(mass); break;}
				//if(fabs(tag_eta)< xbins[num_eta] && fabs(tag_eta)< xbins[num_eta+1]) {th2fs[num_eta]->Fill(mass); break;}
			//}
		}
		//cout << "test" << endl;
		if(pt>20 && fabs(eta)<2.4 && tag_pt>20 && fabs(tag_eta)<2.4 && DoubleIsoMu17Mu8dZ_Mu17leg>0 && mass> 81 && mass<101){
			heta_dZ->Fill(eta, tag_eta);
			//for( num_eta=0 ; num_eta<4; num_eta++){
				//if(fabs(eta)< xbins[num_eta] && fabs(eta)< xbins[num_eta+1]) {th3fs[num_eta]->Fill(mass); break;}
				//if(fabs(tag_eta)< xbins[num_eta] && fabs(tag_eta)< xbins[num_eta+1]) {th4fs[num_eta]->Fill(mass); break;}
			//}

			//cout << "entry" << i << "pt" << pair_pt<< endl;
		}
	}

	TH2D * heta_eff = (TH2D*)heta_dZ->Clone("heta_eff");
	heta_eff->Sumw2();
	//heta_eff->Divide(heta_dZ, heta_a, 1, 1, "b");
	TCanvas * C = new TCanvas();
	C->Draw();
	//heta_eff->SetMarkerStyle(20);
	//heta_eff->SetMarkerColor(4);
	heta_eff->SetTitle("dZ_num_"+NAME);
	heta_eff->GetXaxis()->SetTitle("eta");
	heta_eff->GetYaxis()->SetTitle("tag_eta");
	heta_eff->SetStats(0);
	heta_eff->Draw("colz:TEXTE");


        TFile * file = new TFile(outfile, "recreate");
        heta_eff->Write();
        file->Close();

        C->SaveAs("dZ_num_eta_"+NAME+".pdf");

}
void draw_eta_num(){
        TString filenameData = "Eta_effData.root";
        TString filenameMC = "Eta_effMC.root";
	TString fileMC = "../newDoubleMuonTree/tnpZ_theTreeCleanedMC.root";
	TString fileData = "/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/MuonAnalysis/TagAndProbe/test/zmumu/tnpZ_DatanoCCC.root";//"doubleMuonTrees/tnpZ_theTreeCleaned.root";
        //TString fileMC = "newDoubleMuonTree/TnPtreeMC.root";
        //TString fileData = "doubleMuonTrees/tnpZ_Data_25ns_run2015D_doubleMuon.root";
        Eff( fileData, filenameData, "data");
        /*Eff( fileMC, filenameMC, "MC");

	TFile * hDataEta = new TFile("Eta_effData.root");
	TH2F * histDE = (TH2F *)hDataEta->Get("heta_eff");
	TFile * hMCEta = new TFile("Eta_effMC.root"); 
	TH2F * histME = (TH2F *)hMCEta->Get("heta_eff");
	TH2F * histDM_eta = (TH2F *)histDE->Clone("histDM_eta");
	histDM_eta->Sumw2();
	histDM_eta->Divide(histDE, histME, 1, 1, "b");
	histDM_eta->SetTitle("dZ eff Data/MC");
	histDM_eta->GetXaxis()->SetTitle("muon1 eta");
	histDM_eta->GetYaxis()->SetTitle("muon2 eta");
	
	TCanvas * C3 = new TCanvas();
	C3->Draw();
	histDM_eta->Draw("colz:TEXTE");
	C3->SaveAs("dZ_eta_DM.pdf");	
	
*/


}




