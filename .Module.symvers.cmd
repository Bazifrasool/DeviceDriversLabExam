cmd_/home/hydra/Desktop/folder/Module.symvers := sed 's/ko$$/o/' /home/hydra/Desktop/folder/modules.order | scripts/mod/modpost -m -a   -o /home/hydra/Desktop/folder/Module.symvers -e -i Module.symvers   -T -