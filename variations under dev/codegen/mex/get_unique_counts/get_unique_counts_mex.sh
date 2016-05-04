MATLAB="/Applications/MIT/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/spnba/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for get_unique_counts" > get_unique_counts_mex.mki
echo "CC=$CC" >> get_unique_counts_mex.mki
echo "CFLAGS=$CFLAGS" >> get_unique_counts_mex.mki
echo "CLIBS=$CLIBS" >> get_unique_counts_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> get_unique_counts_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> get_unique_counts_mex.mki
echo "CXX=$CXX" >> get_unique_counts_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> get_unique_counts_mex.mki
echo "CXXLIBS=$CXXLIBS" >> get_unique_counts_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> get_unique_counts_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> get_unique_counts_mex.mki
echo "LD=$LD" >> get_unique_counts_mex.mki
echo "LDFLAGS=$LDFLAGS" >> get_unique_counts_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> get_unique_counts_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> get_unique_counts_mex.mki
echo "Arch=$Arch" >> get_unique_counts_mex.mki
echo OMPFLAGS= >> get_unique_counts_mex.mki
echo OMPLINKFLAGS= >> get_unique_counts_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> get_unique_counts_mex.mki
echo "EMC_CONFIG=optim" >> get_unique_counts_mex.mki
"/Applications/MIT/MATLAB_R2015b.app/bin/maci64/gmake" -B -f get_unique_counts_mex.mk
