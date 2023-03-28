#!/bin/bash

function help()
{
	echo "Usage: "
	echo "$(basename $0) <-h> <-l> < >"
	echo " "
	echo "       -h    Show Usage"
	echo "       -l    Show Crontab scheduler format"
}

function crontab_format
{

	echo "1 - Minute (0-59)"
	echo "2 - Hours (0-23)"
	echo "3 - Day of the month (0-31)"
	echo "4 - Month (0-12) # 12 == December"
	echo "5 - Day of the week (0-7) # 0 == Sunday"
	echo "  "
	echo "*  *  *  *  *  /path"
	echo "|  |  |  |  |"
	echo "|  |  |  |   ---- Day of the week"
	echo "|  |  |   ------- Month"
	echo "|  |   ---------- Day of the month"
	echo "|   ------------- Hour"
	echo " ---------------- Minute"
	echo " "
}

if [ -n "$1" ]; then
case "$1" in 
	-h | --help)
		help
		exit 0
		;;
	-l | --crontab-format)
		crontab_format
		exit 0
		;;
	*)
		echo "Not an option"	
esac
else 

	re='^[0-9]+$'

	read -p "Minute > " minute
	if [ $minute -lt 0 ] || [ $minute -gt 59 ]; then
		echo "Wrong value for minute (0-59)"
		exit 2
	fi
	read -p "Hour > " hour
	if [ $hour -lt 0 ] || [ $hour -gt 23 ]; then
		echo "Wrong value for hour (0-23)"
		exit 2
	fi
	read -p "Day of the month > " day_of_the_month
	if [ $day_of_the_month -lt 0 ] || [ $day_of_the_month -gt 31 ]; then
		echo "Wrong value for day of the month (0-31)"
		exit 2
	fi
	read -p "Month > " month
	if [ $month -lt 0 ] || [ $month -gt 12 ]; then
		echo "Wrong value for month (0-12)"
		exit 2
	fi
	read -p "Day of the week > " day_of_the_week
	if [ $day_of_the_week -lt 0 ] || [ $day_of_the_week -gt 12 ]; then
		echo "Wrong value for day of the week (0-7)"
		exit 2
	fi

fi


