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
repair_design
repair_timing -skip_pin_swap -skip_gate_cloning
puts "reporting timing.."
report_tns
report_wns
report_checks -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded -slack_max -0.000 -group_count 1000000 > setup.rpt
report_cell_usage -verbose
report_instance -connections
puts "writing optimized def.."
write_def /mnt/c/Users/user/Desktop/eda/competition/ICCAD25_PorbC/aes_cipher_top/placed_opt.def

report_power