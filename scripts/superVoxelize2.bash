#!/bin/bash


#SBATCH --job-name=superVoxelize
#SBATCH --output=MatlabJob-%j.out
#SBATCH --error=MatlabJob-%j.err
#SBATCH --mem=128000
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=20

# args are [scriptname] [imgFilePath] [unitTest]

COMMANDS="\
\
addpath(genpath('/om/user/nbarry/')); \
addpath(genpath('/home/nbarry/')); \
global addr;addr='nbarry@media.mit.edu'; \
pool=parpool(maxNumCompThreads,'IdleTimeout',1440); \
disp(pool); \
\
imgFilePath='$2'; \
unitTest = $3; \
\
\
try; \
      	$1; \
catch errorInfo; \
        sendEmailOnFailure(errorInfo,addr); \
end; \
delete(pool); \
exit; \
					"

# print commands to console
echo ${COMMANDS}

# run matlab with commands
matlab -nosplash -nodesktop -r "${COMMANDS}"

# send email when the job exits
mailx -s "job %j exited" < /dev/null "nbarry@media.mit.edu"



