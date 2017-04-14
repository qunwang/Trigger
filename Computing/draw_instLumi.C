



void draw_instLumi(){

    //TFile * fopen = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_Mu17Mu8Clean_ICHEP_runBCDmu17v2.root");
    TFile * fopen = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_eff_Mu17Mu8Clean_ICHEP_runBCDdoub22.root");
    TTree * tree = (TTree *)fopen->Get("tpTree/fitter_tree");

    Float_t weightLumi;
    Float_t tag_instLumi;
    tree->SetBranchAddress("weightLumi", &weightLumi);
    tree->SetBranchAddress("tag_instLumi", &tag_instLumi);

    TH1D * hLumi = new TH1D("hLumi", "hLumi", 100, 0., 11000); 
    TH1D * Hlumi = new TH1D("Hlumi", "Hlumi", 100, 0., 11000); 

    Long64_t num = tree->GetEntries();    
    //for(int i=50000; i < 51000; i++){
    for(int i=0; i < num; i++){
	tree->GetEntry(i);
    //    cout << "instLumi" << tag_instLumi << "weigh" << weightLumi << "instL*weight" << tag_instLumi*weightLumi << endl;
	hLumi->Fill(tag_instLumi);
	Hlumi->Fill(tag_instLumi, weightLumi);

    }	

    TCanvas * C1 = new TCanvas();
    C1->cd();
    hLumi->Draw();
    Hlumi->Draw("same");
    //C1->SaveAs("singleMuon_instlumiCOM.pdf");
    //C1->SaveAs("singleMuon_instlumiCOM.png");
    C1->SaveAs("doubleMuon_instlumiCOM.pdf");
    C1->SaveAs("doubleMuon_instlumiCOM.png");

}
