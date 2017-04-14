#include "TTree.h"
#include "TFile.h"
#include "TStopwatch.h"
#include "TSystem.h"
#include "TRandom.h" 
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <TH1.h>
#include <TH2.h>

// (MC)
//   root -b -q -l  /afs/cern.ch/user/a/agrebeny/eos/cms/store/group/phys_smp/VJets/Bonzai13TeVoutput/tmp/test_WithWeights_new_Lumi.root cleanPairs.cxx++  

// /afs/cern.ch/user/a/agrebeny/eos/cms/store/group/phys_muon/agrebeny/totalData.root
// Data (lumi reweighted) /afs/cern.ch/user/a/agrebeny/eos/cms/store/group/phys_smp/VJets/Bonzai13TeVoutput/tmp/test_data_lumirew.root

void cleanPairs_mu17(){
    using namespace std;
    TTree *tIn  = (TTree *) gFile->Get("tpTree/fitter_tree");
    Float_t pt, abseta, tag_pt, tag_eta, tag_abseta;
    Int_t DenomDz, Dz, DzTkM8, DenomMu17Eff, Mu17Eff, DenomMu17TkMu8Eff, EffMu17Mu8, EffMu17TkMu8, pathOr, pathOrMu20, EffMu17Mu8nodz, EffMu17TkMu8nodz, pathOrnodz;
    Int_t EffMu8orTkMu8dZ;
    Int_t tag_DoubleIsoMu17Mu8_Mu17leg, DoubleIsoMu17Mu8_Mu8leg, DoubleIsoMu17Mu8_Mu17leg, tag_DoubleIsoMu17Mu8_Mu8leg, tag_DoubleIsoMu17Mu8dZ_Mu17leg,   DoubleIsoMu17Mu8dZ_Mu17leg, Mu17_IsoTrkVVL, tag_Mu17_IsoTrkVVL, tag_IsoMu20, IsoMu20, tag_IsoTkMu20, IsoTkMu20 ;
    Int_t tag_DoubleIsoMu17Mu8_IsoMu17leg, DoubleIsoMu17Mu8_IsoMu8leg, DoubleIsoMu17Mu8_IsoMu17leg, tag_DoubleIsoMu17Mu8_IsoMu8leg;
    Int_t Mu17, tag_Mu17;

    Int_t tag_DoubleIsoMu17TkMu8_Mu17leg, DoubleIsoMu17TkMu8_TkMu8leg, DoubleIsoMu17TkMu8_Mu17leg, tag_DoubleIsoMu17TkMu8_TkMu8leg, tag_DoubleIsoMu17TkMu8dZ_Mu17,   DoubleIsoMu17TkMu8dZ_Mu17;
    Int_t tag_DoubleIsoMu17TkMu8_IsoMu17leg, DoubleIsoMu17TkMu8_IsoMu8leg, DoubleIsoMu17TkMu8_IsoMu17leg, tag_DoubleIsoMu17TkMu8_IsoMu8leg;

   Float_t combRelIsoPF04dBeta, tag_combRelIsoPF04dBeta;
   Float_t mass;
   Int_t Tight2012, tag_Tight2012;

   Float_t tag_instLumi;
   Float_t weightLumi;

   Int_t mcTrue;
   Int_t counter = 0;

   //UInt_t event;
   ULong64_t event;
  
    tIn->SetBranchAddress("mcTrue", &mcTrue);
    tIn->SetBranchAddress("Tight2012", &Tight2012);
    tIn->SetBranchAddress("tag_Tight2012", &tag_Tight2012);
    tIn->SetBranchAddress("pt", &pt);
    tIn->SetBranchAddress("mass", &mass);
    tIn->SetBranchAddress("tag_instLumi", &tag_instLumi);
    tIn->SetBranchAddress("abseta", &abseta);
    tIn->SetBranchAddress("tag_pt", &tag_pt);
    tIn->SetBranchAddress("tag_eta", &tag_eta);
    tIn->SetBranchAddress("tag_abseta", &tag_abseta);
    tIn->SetBranchAddress("event", &event);

    tIn->SetBranchAddress("tag_IsoTkMu20", &tag_IsoTkMu20);
    tIn->SetBranchAddress("IsoTkMu20", &IsoTkMu20);

    tIn->SetBranchAddress("tag_IsoMu20", &tag_IsoMu20);
    tIn->SetBranchAddress("IsoMu20", &IsoMu20);

    tIn->SetBranchAddress("combRelIsoPF04dBeta", &combRelIsoPF04dBeta);
    tIn->SetBranchAddress("tag_combRelIsoPF04dBeta", &tag_combRelIsoPF04dBeta);
/*
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_Mu17leg", &tag_DoubleIsoMu17Mu8_Mu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_Mu8leg", &DoubleIsoMu17Mu8_Mu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_Mu17leg", &DoubleIsoMu17Mu8_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_Mu8leg", &tag_DoubleIsoMu17Mu8_Mu8leg);
/////////////////////leg with Iso  9 lines below is new for 8X
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu17leg", &tag_DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu8leg", &DoubleIsoMu17Mu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu8leg", &tag_DoubleIsoMu17Mu8_IsoMu8leg);

    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu17leg", &DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu17leg", &tag_DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu8leg", &tag_DoubleIsoMu17TkMu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu8leg", &DoubleIsoMu17TkMu8_IsoMu8leg);

    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_Mu17leg", &DoubleIsoMu17TkMu8_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_Mu17leg", &tag_DoubleIsoMu17TkMu8_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_TkMu8leg", &tag_DoubleIsoMu17TkMu8_TkMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_TkMu8leg", &DoubleIsoMu17TkMu8_TkMu8leg);

    tIn->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8dZ_Mu17leg", &tag_DoubleIsoMu17Mu8dZ_Mu17leg);

    tIn->SetBranchAddress("DoubleIsoMu17TkMu8dZ_Mu17", &DoubleIsoMu17TkMu8dZ_Mu17);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8dZ_Mu17", &tag_DoubleIsoMu17TkMu8dZ_Mu17);

    tIn->SetBranchAddress("Mu17_IsoTrkVVL", &Mu17_IsoTrkVVL);
    tIn->SetBranchAddress("tag_Mu17_IsoTrkVVL", &tag_Mu17_IsoTrkVVL);
*/
    tIn->SetBranchAddress("Mu17", &Mu17);
    tIn->SetBranchAddress("tag_Mu17", &tag_Mu17);
    double etabin[5] = {0, 0.9, 1.2, 2.1, 2.4};
/*    TH2F *hr2DMCTrue  = new TH2F("hr2DMCTrue","", 4, etabin, 4, etabin);
    int nBinsX = hr2DMCTrue->GetNbinsX();
    int nBinsY = hr2DMCTrue->GetNbinsY();

    TH2F *hr2DMCTrue1  = new TH2F("hr2DMCTrue1","", 4, etabin, 4, etabin);
 
    float bins[7] = {12, 17, 20, 24, 30, 60, 100};
    TH2F *hrpTtest1  = new TH2F("hrpTtest1","", 6, bins, 6, bins);
    TH2F *hrpTtest   = new TH2F("hrpTtest","", 6, bins, 6, bins);
*/

    // TFile *fOut = new TFile("/tmp/hbrun/tnpZ_theTreeCleaned.root", "RECREATE");

    //TFile *fOut = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_eff_Mu17Mu8Clean.root", "RECREATE");

    //TFile * lumiWeight = new TFile("theOutputFile_BCDv2.root");
    //TH1F * h_lumiWeight = (TH1F *)lumiWeight->Get("theRatio");

    //TFile *fOut = new TFile("/afs/cern.ch/user/q/quwang/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_Mu17Mu8Clean_ICHEP_runBCDmu17.root", "RECREATE");
    //TFile *fOut = new TFile("~/eos/cms/store/user/quwang/Trigger/tnpZ_theTreeCleaned_data_Mu17Mu8Clean_ICHEP_runBCDEFmu17.root", "RECREATE");
    TFile *fOut = new TFile("/tmp/quwang/tnpZ_theTreeCleaned_MC_Mu17Mu8Clean_ICHEP_runBCDEFmu17.root", "RECREATE");



    fOut->mkdir("tpTree")->cd();
    TTree *tOut = tIn->CloneTree(0);
    // here we add branches
/*
    tOut->Branch("DenomDz", &DenomDz, "DenomDz/I)");
    tOut->Branch("Dz", &Dz, "Dz/I)");
    tOut->Branch("DzTkM8", &DzTkM8, "DzTkM8/I)");

    tOut->Branch("EffMu17Mu8", &EffMu17Mu8, "EffMu17Mu8/I)");
    tOut->Branch("EffMu17TkMu8", &EffMu17TkMu8, "EffMu17TkMu8/I)");
    tOut->Branch("pathOr", &pathOr, "pathOr/I)");
    tOut->Branch("pathOrMu20", &pathOrMu20, "pathOrMu20/I)");

    tOut->Branch("EffMu8orTkMu8dZ", &EffMu8orTkMu8dZ, "EffMu8orTkMu8dZ/I)");
// nodz 
    tOut->Branch("EffMu17Mu8nodz", &EffMu17Mu8nodz, "EffMu17Mu8nodz/I)");
    tOut->Branch("EffMu17TkMu8nodz", &EffMu17TkMu8nodz, "EffMu17TkMu8nodz/I)");
    tOut->Branch("pathOrnodz", &pathOrnodz, "pathOrnodz/I)");

*/
//    tOut->Branch("DenomMu17Eff", &DenomMu17Eff, "DenomMu17Eff/I)");
    tOut->Branch("Mu17Eff", &Mu17Eff, "Mu17Eff/I)");
//    tOut->Branch("DenomMu17TkMu8Eff", &DenomMu17TkMu8Eff, "DenomMu17TkMu8Eff/I)");

//    tOut->Branch("weightLumi", &weightLumi, "weightLumi/F)");
    
    int step = tIn->GetEntries()/100;
    double evDenom = 100.0/double(tIn->GetEntries());
    TStopwatch timer; timer.Start();
	float ptNow, tagPtNow;
    float ptNext, tagPtNext;
    TRandom *rando = new TRandom();
    for (int i = 0, n = tIn->GetEntries(); i < n; ++i) {
    //for (int i = 0, n = 1000; i < n; ++i) {
        tIn->GetEntry(i);
        
/*        
        if ((i+1) % step == 0) {
            double totalTime = timer.RealTime()/60.; timer.Continue();
            double fraction = double(i+1)/double(n+1), remaining = totalTime*(1-fraction)/fraction;
            printf("Done %9d/%9d   %5.1f%%   (elapsed %5.1f min, remaining %5.1f min)\n", i, n, i*evDenom, totalTime, remaining);
            fflush(stdout);
        }
*/       
/*        ptNow = pt;
        tagPtNow = tag_pt;
        
        tIn->GetEntry(i+1);
        ptNext = pt;
        tagPtNext = tag_pt;
  */
    /*  
        if ((ptNext==tagPtNow)&&(tagPtNext==ptNow)){
        //   printf("found a double pair ! \n");
            float theRand = rando->Uniform(0,2);
            if (theRand>=1) tIn->GetEntry(i); else tIn->GetEntry(i+1);
            i++;
        }
        else tIn->GetEntry(i);
*/
        // add branches
       // cout << tag_DoubleIsoMu17Mu8_Mu17leg << "\n";
       //

       // cout << tag_pt << " , " << pt << "\n";
          
/*
  for (int i(1); i <= nBinsY ; i++) {
        for (int j(1); j <= nBinsX; j++) {

           if(tag_eta < etabin[i+1] && tag_eta < etabin[i]  &&  abseta < etabin[j+1] && abseta < etabin[j])   // probe x axis
          //  hr2DMCTrue -> SetBinContent(j,i, 1);
              hr2DMCTrue -> Fill(abseta, tag_eta);
        
        }
  }
*/
  
//      if(mcTrue && tag_pt > 20. && tag_pt < 9999. && pt > 20. && pt < 9999.)
//      hr2DMCTrue -> Fill(abseta, tag_eta);

        if(tag_eta < 0.9 && tag_eta > 0.0 && abseta < 0.9 && abseta > 0.0)  counter++;

	if(tag_Mu17 && combRelIsoPF04dBeta<0.25  && Tight2012 && tag_Tight2012 && tag_pt>20 && pt>20){
	//if(tag_Mu17 && combRelIsoPF04dBeta<0.25  && Tight2012  && tag_pt>20 && pt>20){

       //        if(abseta < 0.9 && abseta < 0.0) hr2DMCTrue -> Fill(abseta, tag_eta);
       //  if(tag_eta < 1.2 && tag_eta < 0.9 &&  abseta < 1.2 && abseta < 0.9) hr2DMCTrue -> Fill(abseta, tag_eta);
       //  if(tag_eta < 1.2 && tag_eta < 1.2 &&  abseta < 1.2 && abseta < 1.2) hr2DMCTrue -> Fill(abseta, tag_eta);


/*
        DenomDz = 0;
        if((tag_DoubleIsoMu17Mu8_Mu17leg&&DoubleIsoMu17Mu8_Mu8leg)||(DoubleIsoMu17Mu8_Mu17leg&&tag_DoubleIsoMu17Mu8_Mu8leg))
        DenomDz = 1;

        Dz = 0;
        if(DoubleIsoMu17Mu8dZ_Mu17leg||tag_DoubleIsoMu17Mu8dZ_Mu17leg) 
        Dz = 1;
//----------------------with dz -----------------------------
        EffMu17Mu8 = 0;
        //if((tag_DoubleIsoMu17Mu8dZ_Mu17leg&&DoubleIsoMu17Mu8_Mu8leg)||(DoubleIsoMu17Mu8dZ_Mu17leg&&tag_DoubleIsoMu17Mu8_Mu8leg))
        if((tag_DoubleIsoMu17Mu8dZ_Mu17leg&&DoubleIsoMu17Mu8_IsoMu8leg)||(DoubleIsoMu17Mu8dZ_Mu17leg&&tag_DoubleIsoMu17Mu8_IsoMu8leg))
        EffMu17Mu8 = 1;

        EffMu17TkMu8 = 0;
        //if((tag_DoubleIsoMu17TkMu8dZ_Mu17&&DoubleIsoMu17TkMu8_TkMu8leg)||(DoubleIsoMu17TkMu8dZ_Mu17&&tag_DoubleIsoMu17TkMu8_TkMu8leg))
        if((tag_DoubleIsoMu17TkMu8dZ_Mu17&&DoubleIsoMu17TkMu8_IsoMu8leg)||(DoubleIsoMu17TkMu8dZ_Mu17&&tag_DoubleIsoMu17TkMu8_IsoMu8leg))
        EffMu17TkMu8 = 1;

        pathOr=0;
        if(EffMu17Mu8||EffMu17TkMu8)
        pathOr=1;
*/
	//int bin = h_lumiWeight->FindBin(tag_instLumi);
	//cout << "bin: " << bin <<  " weightLumi: " << weightLumi << endl;
	//weightLumi = h_lumiWeight->GetBinContent(bin); 

        // cout << "mcTrue:  "  << mcTrue << "\n";
//        if((EffMu17Mu8||EffMu17TkMu8)&& mcTrue && tag_pt > 20. && tag_pt < 9999. && pt > 20. && pt < 9999.){
//          hr2DMCTrue1 -> Fill(abseta, tag_eta);

/*
        for (int i(1); i <= nBinsY ; i++) {
            for (int j(1); j <= nBinsX; j++) {

            if(tag_eta < etabin[i+1] && tag_eta < etabin[i]  &&  abseta < etabin[j+1] && abseta < etabin[j])   // probe x axis
            //  hr2DMCTrue -> SetBinContent(j,i, 1);
            hr2DMCTrue1 -> Fill(abseta, tag_eta);
        
           }
        }
*/

//         }

/*
        pathOrMu20=0;
        if(EffMu17Mu8||EffMu17TkMu8||tag_IsoMu20||IsoMu20||tag_IsoTkMu20||IsoTkMu20)
        pathOrMu20=1;

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

        EffMu8orTkMu8dZ=0;
        if(EffMu17Mu8nodz||EffMu17TkMu8)
        EffMu8orTkMu8dZ=1;
//-----------------------------------------------------------------------
        DzTkM8 = 0;
        if(DoubleIsoMu17TkMu8dZ_Mu17||tag_DoubleIsoMu17TkMu8dZ_Mu17) 
        DzTkM8 = 1;

        // ----------- new Dz eff (require Mu17_IsoTrkVVL to be on)

        DenomMu17Eff=0;
        if((Mu17_IsoTrkVVL||tag_Mu17_IsoTrkVVL)&&((tag_DoubleIsoMu17Mu8_Mu17leg&&DoubleIsoMu17Mu8_Mu8leg)||(DoubleIsoMu17Mu8_Mu17leg&&tag_DoubleIsoMu17Mu8_Mu8leg)))
        DenomMu17Eff=1;

        DenomMu17TkMu8Eff=0;
        if((Mu17_IsoTrkVVL||tag_Mu17_IsoTrkVVL)&&((tag_DoubleIsoMu17TkMu8_Mu17leg&&DoubleIsoMu17TkMu8_TkMu8leg)||(DoubleIsoMu17TkMu8_Mu17leg&&tag_DoubleIsoMu17TkMu8_TkMu8leg)))
        DenomMu17TkMu8Eff=1;
//	cout << " pathOrnodz " << pathOrnodz << " EffMu17TkMu8nodz " << EffMu17TkMu8nodz << endl;
// HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL

       // ----------- ref trigger Mu 17
*/
        Mu17Eff = 0;
        //if(Mu17_IsoTrkVVL||tag_Mu17_IsoTrkVVL)
        if(Mu17||tag_Mu17)
        Mu17Eff = 1;

	//test of asymmetry
//	if(mass>76 && mass <125 && Mu17Eff>0 && EffMu17Mu8nodz> EffMu17TkMu8nodz && pt>20 && tag_pt>20 && abs(abseta)<2.4 && abs(tag_abseta)<2.4 && Tight2012>0 && tag_Tight2012>0 && (combRelIsoPF04dBeta>-0.5 && combRelIsoPF04dBeta<0.25) && (tag_combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta<0.25))cout << "pathOrnodz" << pathOrnodz << EffMu17TkMu8nodz << EffMu17Mu8nodz << "eta " << abseta << "tag_eat" << tag_abseta << endl;
//	if(mass>76 && mass <125 && Mu17Eff>0 && EffMu17TkMu8< pathOr && pt>20 && tag_pt>20 && abs(abseta)<2.4 && abs(tag_abseta)<2.4 && Tight2012>0 && tag_Tight2012>0&& (combRelIsoPF04dBeta>-0.5 && combRelIsoPF04dBeta<0.25) && (tag_combRelIsoPF04dBeta>-0.5 && tag_combRelIsoPF04dBeta<0.25))cout << "pathOr" << pathOr << EffMu17TkMu8 << EffMu17Mu8 << "eta " << abseta << "tag_eat" << tag_abseta << endl;
/*
        if(Mu17Eff && EffMu17TkMu8 && abs(abseta)<2.4 && abs(tag_eta)<2.4)
        hrpTtest1  -> Fill(pt, tag_pt);

        if(Mu17Eff && abs(abseta)<2.4 && abs(tag_eta)<2.4)
        hrpTtest  -> Fill(pt, tag_pt);
*/
        // cout << "DenomDz  " <<  DenomDz << "\n";
        // cout << Dz << "\n";
        // cout << DenomMu17Eff << " , " << Mu17Eff << "\n";

        tOut->Fill();
	}
       // printf("event=%i, pt=%f, abseta=%f, tag_pt=%f, tag_eta=%f \n", event, pt, abseta, tag_pt, tag_eta);
        
    }
/*
    hr2DMCTrue->Write();
    hr2DMCTrue1->Write();
    hrpTtest1->Write(); 
    hrpTtest->Write();
    cout << counter << "\n";
  */  
    tOut->AutoSave(); // according to root tutorial this is the right thing to do
    fOut->Close();
}
