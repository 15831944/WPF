创建目录时取消息 创建解决方案目录的选项（不必）

# VC 工程配置

VC12
输出目录
$(ProjectDir)..\..\output\$(ProjectName)\$(Configuration)\
中继目录
$(ProjectDir)..\..\Intermediate\$(ProjectName)\$(Configuration)\


包含目录
..\..\include\ffmpeg-2.4.5-win32-dev\include

库目录
..\..\include\ffmpeg-2.4.5-win32-dev\lib

生成后事件，拷贝EXE,  PDB，要先 【是(/DEBUG)】
xcopy "$(TargetDir)$(TargetFileName)" "$(TargetDir)..\..\ManageSystem\$(Configuration)\" /Y
xcopy "$(TargetDir)$(TargetName).pdb" "$(TargetDir)..\..\ManageSystem\pdb\" /Y


WPF 在 csproj 文件中设置

中继目录
<BaseIntermediateOutputPath>$(ProjectDir)..\..\Intermediate\$(AssemblyName)\</BaseIntermediateOutputPath>

输出目录 Debug  Release 都要设置
<OutputPath>$(ProjectDir)..\..\output\$(AssemblyName)\$(Configuration)\</OutputPath>

生成后事件，拷贝EXE,  PDB  些处拷贝到文件结尾处  <Project> 结点内</Project>
<PropertyGroup>
	<PostBuildEvent>xcopy "$(TargetDir)$(TargetFileName)" "$(TargetDir)..\..\ManageSystem\$(Configuration)\" /Y
	xcopy "$(TargetDir)$(TargetName).pdb" "$(TargetDir)..\..\ManageSystem\pdb\" /Y</PostBuildEvent>
</PropertyGroup>