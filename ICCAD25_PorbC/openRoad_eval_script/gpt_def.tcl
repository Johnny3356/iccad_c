########################################################################
# opt_def.tcl
#  — 读取 Liberty, LEF, DEF, SDC
#  — 估 parasitics
#  — 用 repair_design 做一次全流程 timing‐driven 优化
#  — 再次估 parasitics & 输出优化后的 DEF + report
########################################################################

# 1) 读时序库
puts "############ Read Liberty ############"
foreach libFile [glob "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/LIB/*nldm*.lib"] {
    puts " lib: $libFile"
    read_liberty $libFile
}

# 2) 读技术 LEF + cell LEF
puts "############ Read Tech LEF ############"
read_lef "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/techlef/asap7_tech_1x_201209.lef"
puts "############ Read Cell LEF ############"
foreach lef [glob "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/LEF/*.lef"] {
    read_lef $lef
}

# 3) 读 DEF + SDC
puts "############ Read DEF ############"
read_def  "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.def"
puts "############ Read SDC ############"
read_sdc  "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/aes_cipher_top.sdc"

# 4) Estimate parasitics
puts "############ Estimate Parasitics ############"
source "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/ASAP7/setRC.tcl"
estimate_parasitics -placement

# 5) Timing‐driven 全流程优化
puts "############ Timing‐Driven Optimization ############"
# 设置一个最大 transition 目标（根据你的 report_checks 输出调整）
#set_max_transition 0.1 [current_design]

# 自动插 buffer、gate sizing、pin swap、instance clone 等
repair_design

# 插入完 buffer/resize 之后，再次增量估 parasitics
estimate_parasitics -placement

# 6) 输出优化后的 DEF
puts "############ Write Optimized DEF ############"
write_def "/mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/placed_opt.def"

# 7) 最终 PPA 报告
puts "############ Final Reports ############"
report_tns
report_wns
report_power

puts "Done."
