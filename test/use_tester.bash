#!/bin/bash

export LD_PRELOAD="/home/amaury/Epitech/Delivery/PSU_2017_malloc/libmy_malloc.so $1"
./given_tester $2 $1
export LD_PRELOAD=""

