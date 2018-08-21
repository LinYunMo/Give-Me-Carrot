<GameFile>
  <PropertyGroup Name="GameMenu" Type="Scene" ID="cd2055f3-0f2f-4b22-8143-9d3867b0acd2" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000">
        <Timeline ActionTag="-1940584982" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="enemies/sun1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="30" Tween="False">
            <TextureFile Type="Normal" Path="enemies/sun2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="60" Tween="False">
            <TextureFile Type="Normal" Path="enemies/sun1.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="6" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="bg_grasslands" ActionTag="-1903226290" Tag="16" IconVisible="False" LeftMargin="-0.0085" RightMargin="0.0085" TopMargin="0.0002" BottomMargin="-0.0002" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="639.9915" Y="359.9998" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="background/bg_grasslands.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="grassLong" ActionTag="-1683650284" Tag="15" IconVisible="False" LeftMargin="-0.0026" RightMargin="0.0026" TopMargin="580.0001" BottomMargin="-0.0001" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="140.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="639.9974" Y="69.9999" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0972" />
            <PreSize X="1.0000" Y="0.1944" />
            <FileData Type="Normal" Path="tiles/GrassLands.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="helfGrass_1" ActionTag="276217878" Tag="21" IconVisible="False" LeftMargin="380.9006" RightMargin="689.0994" TopMargin="419.8645" BottomMargin="260.1355" ctype="SpriteObjectData">
            <Size X="210.0000" Y="40.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="485.9006" Y="280.1355" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3796" Y="0.3891" />
            <PreSize X="0.1641" Y="0.0556" />
            <FileData Type="Normal" Path="tiles/helfGrass.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="helfGrass_2" ActionTag="1634883291" Tag="26" IconVisible="False" LeftMargin="689.8080" RightMargin="380.1920" TopMargin="301.6216" BottomMargin="378.3784" ctype="SpriteObjectData">
            <Size X="210.0000" Y="40.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="794.8080" Y="398.3784" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6209" Y="0.5533" />
            <PreSize X="0.1641" Y="0.0556" />
            <FileData Type="Normal" Path="tiles/helfGrass.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="title" ActionTag="913302976" Tag="19" IconVisible="False" LeftMargin="170.6753" RightMargin="802.3247" TopMargin="642.3618" BottomMargin="42.6382" ctype="SpriteObjectData">
            <Size X="307.0000" Y="35.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="324.1753" Y="60.1382" />
            <Scale ScaleX="1.7019" ScaleY="1.7019" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2533" Y="0.0835" />
            <PreSize X="0.2398" Y="0.0486" />
            <FileData Type="Normal" Path="tiles/title.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="exit" ActionTag="-525391915" Tag="19" IconVisible="False" LeftMargin="993.1490" RightMargin="216.8510" TopMargin="510.0000" BottomMargin="140.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1028.1490" Y="175.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8032" Y="0.2431" />
            <PreSize X="0.0547" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/exit.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="info" ActionTag="1547502953" Tag="23" IconVisible="False" LeftMargin="506.5463" RightMargin="703.4537" TopMargin="349.8647" BottomMargin="300.1353" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="541.5463" Y="335.1353" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4231" Y="0.4655" />
            <PreSize X="0.0547" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/info.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="start" ActionTag="1462855055" Tag="28" IconVisible="False" LeftMargin="706.2159" RightMargin="503.7841" TopMargin="231.6233" BottomMargin="418.3767" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="741.2159" Y="453.3767" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5791" Y="0.6297" />
            <PreSize X="0.0547" Y="0.0972" />
            <FileData Type="Normal" Path="tiles/start.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ExitDoor" ActionTag="-238879511" Tag="20" IconVisible="False" LeftMargin="1115.0000" RightMargin="95.0000" TopMargin="470.0000" BottomMargin="140.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1150.0000" Y="195.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8984" Y="0.2708" />
            <PreSize X="0.0547" Y="0.1528" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="InfoDoor" ActionTag="-332269428" Tag="24" IconVisible="False" LeftMargin="410.9707" RightMargin="799.0293" TopMargin="309.8647" BottomMargin="300.1353" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="445.9707" Y="355.1353" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3484" Y="0.4932" />
            <PreSize X="0.0547" Y="0.1528" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="StartDoor" ActionTag="-273058127" Tag="29" IconVisible="False" LeftMargin="803.7653" RightMargin="406.2347" TopMargin="191.6216" BottomMargin="418.3784" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="838.7653" Y="473.3784" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6553" Y="0.6575" />
            <PreSize X="0.0547" Y="0.1528" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ladder" ActionTag="-392709218" Tag="25" IconVisible="False" LeftMargin="605.0000" RightMargin="605.0000" TopMargin="286.5880" BottomMargin="153.4120" ctype="SpriteObjectData">
            <Size X="70.0000" Y="280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="293.4120" />
            <Scale ScaleX="1.0000" ScaleY="1.0958" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4075" />
            <PreSize X="0.0547" Y="0.3889" />
            <FileData Type="Normal" Path="tiles/ladder.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sun" ActionTag="-1940584982" Tag="21" IconVisible="False" LeftMargin="68.2389" RightMargin="1069.7611" TopMargin="47.7316" BottomMargin="524.2684" ctype="SpriteObjectData">
            <Size X="142.0000" Y="148.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="139.2389" Y="598.2684" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1088" Y="0.8309" />
            <PreSize X="0.1109" Y="0.2056" />
            <FileData Type="Normal" Path="enemies/sun1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>