# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\VitisIDE\SSD1306\SSD1306_Driver\SSD1306\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\VitisIDE\SSD1306\SSD1306_Driver\SSD1306\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {SSD1306}\
-hw {D:\VitisIDE\SSD1306_Driver\SSD1306.xsa}\
-out {D:/VitisIDE/SSD1306/SSD1306_Driver}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {SSD1306}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
