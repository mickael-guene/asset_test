#!/bin/bash

START=$(date +%s.%N)
TEST_EXPECTED_FAIL=0
TEST_FAIL=0
TEST_UNEXPECTED_OK=0
TEST_OK=0

#get script location
SCRIPTDIR=`dirname $0`
SCRIPTDIR=`(cd $SCRIPTDIR ; pwd)`
#get working directory
TOP=`pwd`

source $SCRIPTDIR/colors.sh

export PATH=${TOP}/install/bin:${SCRIPTDIR}/bin:${PATH}

if [ true == true ]; then
for D in `find ${SCRIPTDIR}/testsuite -maxdepth 1 -type d`; do
    if [ $D != "${SCRIPTDIR}/testsuite" ]; then
        cd $D
        printf "RUNNING %-50s" $(basename $D)
        ./runme.sh > /dev/null 2>&1
        status=$?
        if [ $status != 0 ]; then
            if [ -e "WILL_FAILED" ]; then
                echo -e "${yellow}[ EXPECTED FAIL ]${normal}"
                TEST_EXPECTED_FAIL=$((TEST_EXPECTED_FAIL+1))
            else
                echo -e "${bold}${red}[ FAIL ]${normal}"
                TEST_FAIL=$((TEST_FAIL+1))
            fi
        else
            if [ -e "WILL_FAILED" ]; then
                echo -e "${yellow}[ UNEXPECTED OK ]${normal}"
                TEST_UNEXPECTED_OK=$((TEST_UNEXPECTED_OK+1))
            else
                echo -e "${green}[ OK ]${normal}"
                TEST_OK=$((TEST_OK+1))
            fi
        fi
        make clean  > /dev/null 2>&1
    fi
done
fi

TEST_NB=$((TEST_EXPECTED_FAIL+TEST_FAIL+TEST_UNEXPECTED_OK+TEST_OK))
printf "\nTEST RESULT SUMMARY\n"
printf "###################\n"
printf "%-57s ${bold}${red}[%3d / %2d]${normal}\n" "FAIL" $TEST_FAIL $TEST_NB
printf "%-57s ${yellow}[%3d / %2d]${normal}\n" "EXPECTED FAIL" $TEST_EXPECTED_FAIL $TEST_NB
printf "%-57s ${yellow}[%3d / %2d]${normal}\n" "UNEXPECTED OK" $TEST_UNEXPECTED_OK $TEST_NB
printf "%-57s ${green}[%3d / %2d]${normal}\n" "OK" $TEST_OK $TEST_NB


END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)

printf "\nfull testsuite run in %s seconds\n" $DIFF

exit $TEST_FAIL
