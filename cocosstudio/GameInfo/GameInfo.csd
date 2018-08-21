<GameFile>
  <PropertyGroup Name="GameInfo" Type="Scene" ID="ebdd2c26-e6df-4bf4-a4d2-5ce32535074d" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="90" Speed="1.0000">
        <Timeline ActionTag="973340525" Property="FileData">
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
        <Timeline ActionTag="-1169970827" Property="Position">
          <PointFrame FrameIndex="0" X="260.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="590.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1169970827" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-44875897" Property="Position">
          <PointFrame FrameIndex="0" X="1000.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="670.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-44875897" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="15" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="IntroBG" ActionTag="-1856446420" Tag="16" IconVisible="False" LeftMargin="0.0001" RightMargin="-0.0001" TopMargin="-0.0002" BottomMargin="0.0002" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0001" Y="360.0002" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="background/IntroBG.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sun" ActionTag="973340525" Tag="20" IconVisible="False" LeftMargin="63.9963" RightMargin="1074.0037" TopMargin="46.0000" BottomMargin="526.0000" ctype="SpriteObjectData">
            <Size X="142.0000" Y="148.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="134.9963" Y="600.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1055" Y="0.8333" />
            <PreSize X="0.1109" Y="0.2056" />
            <FileData Type="Normal" Path="enemies/sun1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="grassLong" ActionTag="-2019342525" Tag="17" IconVisible="False" LeftMargin="-0.0002" RightMargin="0.0002" TopMargin="580.0009" BottomMargin="-0.0008" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="140.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="639.9998" Y="69.9992" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0972" />
            <PreSize X="1.0000" Y="0.1944" />
            <FileData Type="Normal" Path="tiles/GrassLands.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cloud" ActionTag="-1990750557" Tag="21" RotationSkewX="30.1739" RotationSkewY="30.1739" IconVisible="False" LeftMargin="1020.0000" TopMargin="53.0000" BottomMargin="533.0000" ctype="SpriteObjectData">
            <Size X="260.0000" Y="134.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1150.0000" Y="600.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8984" Y="0.8333" />
            <PreSize X="0.2031" Y="0.1861" />
            <FileData Type="Normal" Path="enemies/cloud.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="flame" ActionTag="-1169970827" Tag="22" RotationSkewX="90.0000" RotationSkewY="90.0000" IconVisible="False" LeftMargin="239.5000" RightMargin="999.5000" TopMargin="80.0000" BottomMargin="560.0000" ctype="SpriteObjectData">
            <Size X="41.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="260.0000" Y="600.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2031" Y="0.8333" />
            <PreSize X="0.0320" Y="0.1111" />
            <FileData Type="Normal" Path="enemies/flame.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="lighting_yellow" ActionTag="-44875897" Tag="23" RotationSkewX="90.0000" RotationSkewY="90.0000" IconVisible="False" LeftMargin="972.5000" RightMargin="252.5000" TopMargin="63.0000" BottomMargin="543.0000" ctype="SpriteObjectData">
            <Size X="55.0000" Y="114.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1000.0000" Y="600.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7813" Y="0.8333" />
            <PreSize X="0.0430" Y="0.1583" />
            <FileData Type="Normal" Path="enemies/lighting_yellow.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="information" ActionTag="1506596511" Tag="27" IconVisible="False" LeftMargin="492.0000" RightMargin="492.0000" TopMargin="121.9999" BottomMargin="202.0001" ctype="SpriteObjectData">
            <Size X="296.0000" Y="396.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="400.0001" />
            <Scale ScaleX="1.3152" ScaleY="1.3152" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5556" />
            <PreSize X="0.2313" Y="0.5500" />
            <FileData Type="Normal" Path="tiles/information.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="MenuDoor" ActionTag="2011576529" Tag="19" IconVisible="False" LeftMargin="1053.0754" RightMargin="180.9246" TopMargin="502.0000" BottomMargin="172.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="110.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1076.0754" Y="195.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8407" Y="0.2708" />
            <PreSize X="0.0359" Y="0.0639" />
            <FileData Type="Normal" Path="tiles/DoorOpen.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="menu" ActionTag="-863066678" Tag="18" IconVisible="False" LeftMargin="927.2622" RightMargin="306.7378" TopMargin="522.0000" BottomMargin="152.0000" ctype="SpriteObjectData">
            <Size X="70.0000" Y="70.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="950.2622" Y="175.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7424" Y="0.2431" />
            <PreSize X="0.0359" Y="0.0639" />
            <FileData Type="Normal" Path="tiles/menu.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>