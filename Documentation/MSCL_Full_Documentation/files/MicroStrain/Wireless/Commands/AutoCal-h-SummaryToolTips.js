NDSummary.OnToolTipsLoaded("File:MicroStrain/Wireless/Commands/AutoCal.h",{1460:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1460\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">AutoCalResult</div></div></div><div class=\"TTSummary\">Abstract base class for AutoCal result classes.</div></div>",1462:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1462\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalCompletionFlag completionFlag() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the WirelessTypes::AutoCalCompletionFlag of the AutoCal operation result.</div></div>",1463:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1463\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual void</span> parse(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Bytes&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">autoCalInfo</td></tr></table></td><td class=\"PAfterParameters\">) = <span class=\"SHNumber\">0</span></td></tr></table></div><div class=\"TTSummary\">Parses the auto cal info bytes sent in the successful response packet.</div></div>",1465:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1465\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalCompletionFlag m_completionFlag</div><div class=\"TTSummary\">The WirelessTypes::AutoCalCompletionFlag of the AutoCal operation.</div></div>",1466:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1466\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">AutoCalResult_shmLink</div></div></div><div class=\"TTSummary\">Holds the result information from an autoCal_shmLink command.</div></div>",1468:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1468\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag m_errorFlagCh1</div><div class=\"TTSummary\">The WirelessTypes::AutoCalErrorFlag for the channel 1 strain sensor.</div></div>",1469:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1469\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag m_errorFlagCh2</div><div class=\"TTSummary\">The WirelessTypes::AutoCalErrorFlag for the channel 2 strain sensor.</div></div>",1470:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1470\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag m_errorFlagCh3</div><div class=\"TTSummary\">The WirelessTypes::AutoCalErrorFlag for the channel 3 strain sensor.</div></div>",1471:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1471\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> m_offsetCh1</div><div class=\"TTSummary\">The offset applied for the channel 1 strain sensor.</div></div>",1472:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1472\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> m_offsetCh2</div><div class=\"TTSummary\">The offset applied for the channel 2 strain sensor.</div></div>",1473:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1473\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> m_offsetCh3</div><div class=\"TTSummary\">The offset applied for the channel 3 strain sensor.</div></div>",1474:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1474\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> m_temperature</div><div class=\"TTSummary\">The temperature at the time of calibration.</div></div>",1476:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1476\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag errorFlagCh1() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the WirelessTypes::AutoCalErrorFlag for the channel 1 strain sensor.</div></div>",1477:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1477\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag errorFlagCh2() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the WirelessTypes::AutoCalErrorFlag for the channel 2 strain sensor.</div></div>",1478:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1478\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalErrorFlag errorFlagCh3() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the WirelessTypes::AutoCalErrorFlag for the channel 3 strain sensor.</div></div>",1479:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1479\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> offsetCh1() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the offset applied for the channel 1 strain sensor.</div></div>",1480:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1480\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> offsetCh2() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the offset applied for the channel 2 strain sensor.</div></div>",1481:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1481\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> offsetCh3() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the offset applied for the channel 3 strain sensor.</div></div>",1482:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1482\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> temperature() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the temperature (in ?C) at the time of the calibration.</div></div>",1483:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1483\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual void</span> parse(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Bytes&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">autoCalInfo</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">final</span></td></tr></table></div><div class=\"TTSummary\">Parses the auto cal info bytes for the shm-link.</div></div>",1484:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1484\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">AutoCal</div></div></div><div class=\"TTSummary\">Contains logic for the AutoCal Node command.</div></div>",1486:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1486\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> ByteStream buildCommand_shmLink(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Builds the AutoCal command packet for the SHM-Link node.</div></div>",1487:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1487\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">Response</div></div></div><div class=\"TTSummary\">Handles the response to the LongPing Node command</div></div>",1489:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1489\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">Response(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"first\"></td><td class=\"PType\">NodeAddress&nbsp;</td><td></td><td class=\"PName last\">nodeAddress,</td></tr><tr><td class=\"PModifierQualifier first\">WirelessModels::</td><td class=\"PType\">NodeModel&nbsp;</td><td></td><td class=\"PName last\">model,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Version&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">fwVersion,</td></tr><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\">weak_ptr&lt;ResponseCollector&gt;&nbsp;</td><td></td><td class=\"PName last\">collector</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a AutoCal Response object</div></div>",1491:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1491\" class=\"NDPrototype NoParameterForm\">NodeAddress m_nodeAddress</div><div class=\"TTSummary\">The node address to look for in the response.</div></div>",1492:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1492\" class=\"NDPrototype NoParameterForm\">WirelessModels::NodeModel m_model</div><div class=\"TTSummary\">The WirelessModels::NodeModel of the Node we are expecting a response for.</div></div>",1493:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1493\" class=\"NDPrototype NoParameterForm\">Version m_fwVersion</div><div class=\"TTSummary\">The firmware version of the Node we are expecting a response for.</div></div>",1494:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1494\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> m_calStarted</div><div class=\"TTSummary\">Whether the AutoCal has been successfully started or not (as reported by the Node).</div></div>",1495:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1495\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalCompletionFlag m_completionFlag</div><div class=\"TTSummary\">The &lt;AutoCalCompletionFlag&gt; representing the final autocal status.</div></div>",1496:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1496\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> m_timeUntilCompletion</div><div class=\"TTSummary\">The amount of time (in seconds) that the autocal operation will take to complete.&nbsp; This value gets reported by the Node before starting the calibration.</div></div>",1497:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1497\" class=\"NDPrototype NoParameterForm\">Bytes m_infoBytes</div><div class=\"TTSummary\">Contains all of the information bytes from the completion response.</div></div>",1499:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1499\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> calStarted() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets whether the AutoCal operation has started or not.</div></div>",1500:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1500\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> calTime() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the total time (in seconds) that the Node reported it will take to complete the AutoCal operation.</div></div>",1501:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1501\" class=\"NDPrototype NoParameterForm\">WirelessTypes::AutoCalCompletionFlag completionFlag() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the WirelessTypes::AutoCalCompletionFlag of the AutoCal operation.</div></div>",1502:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1502\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">const</span> Bytes&amp; infoBytes() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the information bytes returned from the AutoCal completion packet.</div></div>",1503:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1503\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual bool</span> match(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div><div class=\"TTSummary\">Checks if the WirelessPacket passed in matches the expected response pattern\'s bytes.</div></div>",1504:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1504\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> match_nodeReceived(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the WirelessPacket passed in matches the &quot;Node Received&quot; packet.</div></div>",1505:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1505\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> match_shmLink(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the WirelessPacket matches the SHM-Link AutoCal packet.</div></div>"});