CC="/usr/bin/xcrun -sdk macosx10.11 clang"
CXX="/usr/bin/xcrun -sdk macosx10.11 clang"
CFLAGS="-fno-common -arch x86_64 -mmacosx-version-min=10.11 -fexceptions -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -DMATLAB_MEX_FILE"
CXXFLAGS="-fno-common -arch x86_64 -mmacosx-version-min=10.11 -fexceptions -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -DMATLAB_MEX_FILE"
COPTIMFLAGS="-O2 -DNDEBUG"
CXXOPTIMFLAGS="-O2 -DNDEBUG"
CDEBUGFLAGS="-g"
CXXDEBUGFLAGS="-g"
LD="/usr/bin/xcrun -sdk macosx10.11 clang"
LDXX="/usr/bin/xcrun -sdk macosx10.11 clang"
LDFLAGS="-Wl,-twolevel_namespace -undefined error -arch x86_64 -mmacosx-version-min=10.11 -Wl,-syslibroot,/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -bundle  -Wl,-exported_symbols_list,"/Applications/MIT/MATLAB_R2015b.app/extern/lib/maci64/mexFunction.map" -L"/Applications/MIT/MATLAB_R2015b.app/bin/maci64" -lmx -lmex -lmat -lc++ -Wl,-exported_symbols_list,"/Applications/MIT/MATLAB_R2015b.app/extern/lib/maci64/mexFunction.map""
LDDEBUGFLAGS="-g"
