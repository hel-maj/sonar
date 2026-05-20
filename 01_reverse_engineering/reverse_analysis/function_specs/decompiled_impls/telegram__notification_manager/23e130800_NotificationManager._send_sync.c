/* ===== 23e130800 telegram.notification_manager:79 ===== */
/* ghidra_name=FUN_23e130800 entry=23e130800 size=608 */

undefined8 FUN_23e130800(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *local_68;
  longlong *local_60;
  longlong *local_58;
  
  plVar7 = DAT_23ed6a4e0;
  lVar1 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar7 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar8 = DAT_23ed6a4e0;
  }
  else {
    plVar8 = (longlong *)*DAT_23ed6a4e0;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    plVar9 = plVar8;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar9;
  }
  pcVar5 = _PyRuntime_exref;
  plVar7[2] = lVar1;
  lVar1 = param_3[1];
  lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar7[-1];
  puVar3 = *(undefined8 **)(lVar10 + 8);
  *puVar3 = plVar7 + -2;
  plVar7[-2] = lVar10;
  plVar7[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar10 + 8) = plVar7 + -2;
  if (plVar8 == (longlong *)0x0) {
    plVar8 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar9 = DAT_23ed6a4e0;
  }
  else {
    plVar9 = (longlong *)*plVar8;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    DAT_23ed6a4e0 = plVar9;
    *plVar8 = 1;
  }
  lVar10 = *(longlong *)(pcVar5 + 0x1f8);
  plVar8[2] = lVar1;
  lVar1 = param_3[2];
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar2 = plVar8[-1];
  puVar3 = *(undefined8 **)(lVar10 + 8);
  *puVar3 = plVar8 + -2;
  plVar8[-2] = lVar10;
  plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar10 + 8) = plVar8 + -2;
  if (plVar9 == (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar10 = *plVar9 + 1;
  }
  else {
    DAT_23ed6a4e0 = (longlong *)*plVar9;
    lVar10 = 2;
    *plVar9 = 1;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  lVar2 = *(longlong *)(pcVar5 + 0x1f8);
  plVar9[2] = lVar1;
  lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
  lVar2 = plVar9[-1];
  puVar3 = *(undefined8 **)(lVar1 + 8);
  *puVar3 = plVar9 + -2;
  uVar4 = DAT_23eeaae08;
  plVar9[-2] = lVar1;
  plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar1 + 8) = plVar9 + -2;
  *plVar9 = lVar10;
  uVar6 = DAT_23eea8220;
  *plVar7 = *plVar7 + 1;
  *plVar8 = *plVar8 + 1;
  local_68 = plVar9;
  local_60 = plVar7;
  local_58 = plVar8;
  uVar6 = FUN_23e91eef0(param_1,FUN_23e1470a0,uVar4,uVar6,DAT_23eea8228,DAT_23eeaadc0,&local_68,3,
                        0x500);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  return uVar6;
}
