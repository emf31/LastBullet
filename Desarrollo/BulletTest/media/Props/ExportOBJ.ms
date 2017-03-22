-- edit (objexp.getIniName())
theINI = objimp.getIniName()
setIniSetting theINI "Geometry" "FlipZyAxis" "1"
try destroyDialog objExportRollout catch()
rollout objExportRollout "Obj Sequence Export" width:336 height:72
(
	editText pathEdt "" pos:[0,5] width:284 height:16
	button pathBtn "Open" pos:[288,4] width:43 height:18
	label lbl1 "Frame Padding" pos:[7,50] width:76 height:16
	spinner framePaddingSpn "" pos:[84,50] width:84 height:16 range:[1,10000,1] type:#integer scale:1
	label lbl2 "Start" pos:[8,29] width:32 height:15
	label lbl3 "End" pos:[175,29] width:21 height:15
	spinner startSpn "" pos:[39,28] width:130 height:16 range:[-1e+006,1e+006,animationRange.start] type:#integer scale:1
	spinner endSpn "" pos:[200,28] width:130 height:16 range:[-1e+006,1e+006,animationRange.end] type:#integer scale:1
	button exportBtn "Export" pos:[174,50] width:156 height:17
	
	on pathBtn pressed do
	(
		try
		(
			exportObjPath = getSaveFileName caption:"Set Obj Sequence Path" types:"Obj (*.obj)|*.obj"
			pathEdt.text = exportObjPath
		)catch()
	)
	on exportBtn pressed do
	(
		if pathEdt.text != "" do
		(
			framePaddingVal = framePaddingSpn.value
			file = pathEdt.text
			fileName = (getFilenamePath file) + (getFilenameFile file)
			disableSceneRedraw()
			for t = startSpn.value to endSpn.value do
			(
				slidertime = t
				framePadding = (t as string)
				while framePadding.count < framePaddingVal do
				(
					framePadding = "0" + framePadding
				)
				newFileName = fileName + framePadding + ".obj"
				exportFile newFileName #noPrompt selectedOnly:True
			)
			enableSceneRedraw()
		)
	)
)
createDialog objExportRollout