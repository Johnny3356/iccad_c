puts "reading lib.."
foreach libFile [glob "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/LIB/*nldm*.lib"] {
    puts "lib: $libFile"
    read_liberty $libFile
}
puts "reading lef.."
read_lef /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/techlef/asap7_tech_1x_201209.lef
foreach lef [glob "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/LEF/*.lef"] {
    read_lef $lef
}
puts "reading def.."
read_def /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.def
read_sdc /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.sdc
source /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/setRC.tcl
estimate_parasitics -placement
# === 新增開始：呼叫 placement & timing 優化步驟 ===
# 1) timing‐driven 全局佈局
global_placement -timing_driven \
                 -timing_driven_nets_percentage 10

# 2) 詳細佈局
detailed_placement 
improve_placement

# 3) timing 修復
repair_design -slew_margin 10 -cap_margin 10 -max_utilization 0.8

# 4a) （可選）再細分 setup/hold 修正
repair_timing -setup   -slack_margin 0.05
repair_timing -hold    -allow_setup_violations -slack_margin 0.02

# === 新增結束 ===
puts "writing optimized def.."
write_def /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/placed_opt.def

puts "reporting timing.."
report_tns
report_wns
report_power
