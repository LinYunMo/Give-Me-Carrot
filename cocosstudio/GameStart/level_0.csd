<GameFile>
  <PropertyGroup Name="level_0" Type="Scene" ID="71144d97-64c3-411d-8894-225728faa8b0" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="240" Speed="1.0000">
        <Timeline ActionTag="-57077250" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="120" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="240" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-493252690" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="180" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="74" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="bg_dead" ActionTag="-1907321920" Tag="90" IconVisible="False" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="360.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="background/bg_dead.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="grassLong" ActionTag="1582445308" Tag="91" IconVisible="False" LeftMargin="0.0007" RightMargin="-0.0007" TopMargin="579.9997" BottomMargin="0.0003" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="140.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0007" Y="70.0003" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0972" />
            <PreSize X="1.0000" Y="0.1944" />
            <FileData Type="Normal" Path="tiles/GrassLanddead.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="RestartDoor" ActionTag="-894432383" Tag="92" IconVisible="False" LeftMargin="245.0000" RightMargin="965.0000" TopMargin="469.9993" BottomMargin="140.0007" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="280.0000" Y="195.0007" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2188" Y="0.2708" />
            <PreSize X="0.0547" Y="0.1528" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ExitDoor" ActionTag="-24738752" Tag="93" IconVisible="False" LeftMargin="965.0000" RightMargin="245.0000" TopMargin="470.0000" BottomMargin="140.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1000.0000" Y="195.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7813" Y="0.2708" />
            <PreSize X="0.0547" Y="0.1528" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="exit" ActionTag="1014244744" Tag="94" IconVisible="False" LeftMargin="1095.0000" RightMargin="115.0000" TopMargin="510.0000" BottomMargin="140.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1130.0000" Y="175.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8828" Y="0.2431" />
            <PreSize X="0.0547" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/exitDead.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="restart" ActionTag="-1492991975" Tag="95" IconVisible="False" LeftMargin="115.0000" RightMargin="1095.0000" TopMargin="509.9995" BottomMargin="140.0005" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="150.0000" Y="175.0005" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1172" Y="0.2431" />
            <PreSize X="0.0547" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/restart.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="helltitle" ActionTag="513583481" Tag="96" IconVisible="False" LeftMargin="0.0006" RightMargin="3.9994" TopMargin="622.4829" BottomMargin="27.5171" ctype="SpriteObjectData">
            <Size X="1276.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="638.0006" Y="62.5171" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4984" Y="0.0868" />
            <PreSize X="0.9969" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/helltitle.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="hellquestion" ActionTag="-57077250" Tag="97" IconVisible="False" LeftMargin="248.0000" RightMargin="248.0000" TopMargin="135.0000" BottomMargin="515.0000" ctype="SpriteObjectData">
            <Size X="784.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="550.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7639" />
            <PreSize X="0.6125" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/hellquestion.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="hellquestion1" ActionTag="-493252690" Alpha="0" Tag="98" IconVisible="False" LeftMargin="295.0000" RightMargin="295.0000" TopMargin="285.0000" BottomMargin="365.0000" ctype="SpriteObjectData">
            <Size X="690.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="400.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5556" />
            <PreSize X="0.5391" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/hellquestion1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>