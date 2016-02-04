#!/bin/csh

set LOCALDIR = `pwd`
setenv WORKINGDIR /afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/HLTrigger/Configuration/test#/afs/cern.ch/user/q/quwang/work/Trigger/CMSSW_7_6_3_patch2/src/
setenv LOCAL_PATH runDQM
setenv OUTDIR /store/user/quwang/Trigger
#setenv OUTDIR /store/user/hbrun/dqmTests/720_30julyBuild_std
cd $WORKINGDIR
cmsenv
cp ${1} $LOCALDIR
cd $LOCALDIR
ls 
cmsRun ${1}

echo "end of the job !"
ls 
sleep 120
cmsStage  /tmp/quwang/outputFULLnoccc.root $OUTDIR
