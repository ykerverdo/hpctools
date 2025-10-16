#!/bin/bash
#SBATCH -o %x-%J.out
#SBATCH -e %x-%J.error
#SBATCH --time=0-01:00:00 #requested time to run the job
#SBATCH -n 1   # number of concurrent jobs (64 cores/node)
#SBATCH --mem-per-cpu 4G

./dgesv_v2 1024
./dgesv_v2 2048
./dgesv_v2 4096