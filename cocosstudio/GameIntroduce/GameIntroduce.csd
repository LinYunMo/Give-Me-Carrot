<GameFile>
  <PropertyGroup Name="GameIntroduce" Type="Scene" ID="c44c58f2-dd27-4ea6-bec6-7cbfadcb1705" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="300" Speed="1.0000">
        <Timeline ActionTag="-1481619110" Property="Position">
          <PointFrame FrameIndex="0" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="640.6700" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="120" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="180" X="640.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="240" X="640.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="260" X="720.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="280" X="720.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1481619110" Property="Alpha">
          <IntFrame FrameIndex="0" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="10" Value="179">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="240" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="280" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="300" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1481619110" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="enemies/sun1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="Normal" Path="enemies/sun1.png" Plist="" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-1481619110" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="10" Tween="False" Src="1" Dst="771" />
        </Timeline>
        <Timeline ActionTag="509263438" Property="Position">
          <PointFrame FrameIndex="0" X="1480.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="1480.0000" Y="400.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="120" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="180" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="240" X="640.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="300" X="640.0000" Y="600.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="509263438" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="240" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="300" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1861953928" Property="Position">
          <PointFrame FrameIndex="210" X="640.0000" Y="450.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1861953928" Property="Alpha">
          <IntFrame FrameIndex="210" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="240" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="280" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="300" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="8" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="IntroBG_7" ActionTag="-1451939750" Tag="15" IconVisible="False" LeftMargin="0.0007" RightMargin="-0.0007" TopMargin="-0.0001" BottomMargin="0.0001" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0007" Y="360.0001" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="background/IntroBG.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sun1_1" ActionTag="-1481619110" Alpha="127" Tag="9" IconVisible="False" LeftMargin="569.0000" RightMargin="569.0000" TopMargin="196.0000" BottomMargin="376.0000" ctype="SpriteObjectData">
            <Size X="142.0000" Y="148.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="450.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.6250" />
            <PreSize X="0.1109" Y="0.2056" />
            <FileData Type="Normal" Path="enemies/sun1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cloud_2" ActionTag="509263438" Tag="10" IconVisible="False" LeftMargin="1350.0000" RightMargin="-330.0000" TopMargin="203.0000" BottomMargin="383.0000" ctype="SpriteObjectData">
            <Size X="260.0000" Y="134.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1480.0000" Y="450.0000" />
            <Scale ScaleX="1.3808" ScaleY="1.3808" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="1.1563" Y="0.6250" />
            <PreSize X="0.2031" Y="0.1861" />
            <FileData Type="Normal" Path="enemies/cloud.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="lighting_yellow_4" ActionTag="1861953928" Alpha="0" Tag="12" IconVisible="False" LeftMargin="612.5000" RightMargin="612.5000" TopMargin="213.0000" BottomMargin="393.0000" ctype="SpriteObjectData">
            <Size X="55.0000" Y="114.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="450.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.6250" />
            <PreSize X="0.0430" Y="0.1583" />
            <FileData Type="Normal" Path="enemies/lighting_yellow.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>