MATLAB="/Applications/MIT/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/spnba/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for get_intensity_gradient" > get_intensity_gradient_mex.mki
echo "CC=$CC" >> get_intensity_gradient_mex.mki
echo "CFLAGS=$CFLAGS" >> get_intensity_gradient_mex.mki
echo "CLIBS=$CLIBS" >> get_intensity_gradient_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> get_intensity_gradient_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> get_intensity_gradient_mex.mki
echo "CXX=$CXX" >> get_intensity_gradient_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> get_intensity_gradient_mex.mki
echo "CXXLIBS=$CXXLIBS" >> get_intensity_gradient_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> get_intensity_gradient_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> get_intensity_gradient_mex.mki
echo "LD=$LD" >> get_intensity_gradient_mex.mki
echo "LDFLAGS=$LDFLAGS" >> get_intensity_gradient_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> get_intensity_gradient_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> get_intensity_gradient_mex.mki
echo "Arch=$Arch" >> get_intensity_gradient_mex.mki
echo OMPFLAGS= >> get_intensity_gradient_mex.mki
echo OMPLINKFLAGS= >> get_intensity_gradient_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> get_intensity_gradient_mex.mki
echo "EMC_CONFIG=optim" >> get_intensity_gradient_mex.mki
"/Applications/MIT/MATLAB_R2015b.app/bin/maci64/gmake" -B -f get_intensity_gradient_mex.mk
