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
                echo -e "\e[93m[ EXPECTED FAIL ]\e[0m"
                TEST_EXPECTED_FAIL=$((TEST_EXPECTED_FAIL+1))
            else
                echo -e "\e[1m\e[31m[ FAIL ]\e[0m"
                TEST_FAIL=$((TEST_FAIL+1))
            fi
        else
            if [ -e "WILL_FAILED" ]; then
                echo -e "\e[93m[ UNEXPECTED OK ]\e[0m"
                TEST_UNEXPECTED_OK=$((TEST_UNEXPECTED_OK+1))
            else
                echo -e "\e[32m[ OK ]\e[0m"
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
printf "%-57s \e[1m\e[31m[%3d / %2d]\e[0m\n" "FAIL" $TEST_FAIL $TEST_NB
printf "%-57s \e[93m[%3d / %2d]\e[0m\n" "EXPECTED FAIL" $TEST_EXPECTED_FAIL $TEST_NB
printf "%-57s \e[93m[%3d / %2d]\e[0m\n" "UNEXPECTED OK" $TEST_UNEXPECTED_OK $TEST_NB
printf "%-57s \e[32m[%3d / %2d]\e[0m\n" "OK" $TEST_OK $TEST_NB


END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)

printf "\nfull testsuite run in %s seconds\n" $DIFF

exit $TEST_FAIL
