MATLAB="/Applications/MIT/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/spnba/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for assign6BoundariesNB" > assign6BoundariesNB_mex.mki
echo "CC=$CC" >> assign6BoundariesNB_mex.mki
echo "CFLAGS=$CFLAGS" >> assign6BoundariesNB_mex.mki
echo "CLIBS=$CLIBS" >> assign6BoundariesNB_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> assign6BoundariesNB_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> assign6BoundariesNB_mex.mki
echo "CXX=$CXX" >> assign6BoundariesNB_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> assign6BoundariesNB_mex.mki
echo "CXXLIBS=$CXXLIBS" >> assign6BoundariesNB_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> assign6BoundariesNB_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> assign6BoundariesNB_mex.mki
echo "LD=$LD" >> assign6BoundariesNB_mex.mki
echo "LDFLAGS=$LDFLAGS" >> assign6BoundariesNB_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> assign6BoundariesNB_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> assign6BoundariesNB_mex.mki
echo "Arch=$Arch" >> assign6BoundariesNB_mex.mki
echo OMPFLAGS= >> assign6BoundariesNB_mex.mki
echo OMPLINKFLAGS= >> assign6BoundariesNB_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> assign6BoundariesNB_mex.mki
echo "EMC_CONFIG=optim" >> assign6BoundariesNB_mex.mki
"/Applications/MIT/MATLAB_R2015b.app/bin/maci64/gmake" -B -f assign6BoundariesNB_mex.mk
