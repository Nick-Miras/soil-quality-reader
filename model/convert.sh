#!/bin/bash

scikinC saved/scaler.pkl > saved/scaler.C
m2cgen saved/svm_model.pkl --language c > saved/svm_model.C
m2cgen saved/dt.pkl --language c > saved/dt.C