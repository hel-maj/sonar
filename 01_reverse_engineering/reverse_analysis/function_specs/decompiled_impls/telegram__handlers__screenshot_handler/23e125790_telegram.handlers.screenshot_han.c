/* ===== 23e125790 telegram.handlers.screenshot_han:59 ===== */
/* ghidra_name=forced_23e125790 entry=23e125790 size=590 */

undefined8 * forced_23e125790(longlong param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  longlong lVar11;
  
  plVar10 = DAT_23ed6a4e0;
  lVar2 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar10 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar11 = *plVar10 + 1;
  }
  else {
    lVar11 = 2;
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar7 = DAT_23eea8940;
  plVar10[2] = lVar2;
  uVar8 = DAT_23eeaaf50;
  uVar5 = DAT_23eeaaf20;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  lVar3 = plVar10[-1];
  puVar4 = *(undefined8 **)(lVar2 + 8);
  *puVar4 = plVar10 + -2;
  puVar9 = DAT_23ed91750;
  plVar10[-2] = lVar2;
  plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar2 + 8) = plVar10 + -2;
  *plVar10 = lVar11;
  if (puVar9 == (undefined8 *)0x0) {
    puVar9 = (undefined8 *)FUN_23e916a20(&DAT_23ec10a80,0x2f);
  }
  else {
    DAT_23ed91750 = (undefined8 *)*puVar9;
    DAT_23ed9174c = DAT_23ed9174c + -1;
    if ((longlong)puVar9[2] < 0x2f) {
      puVar9 = (undefined8 *)_PyObject_GC_Resize(puVar9,0x2f);
    }
    *puVar9 = 1;
  }
  puVar9[3] = plVar7;
  puVar9[4] = uVar8;
  puVar9[0x13] = puVar9 + 0x16;
  puVar9[9] = FUN_23e155b20;
  lVar2 = *plVar7;
  puVar9[5] = plVar7;
  *plVar7 = lVar2 + 2;
  uVar8 = 0;
  puVar9[0x15] = plVar10;
  puVar9[8] = 0;
  iVar1 = *(int *)(param_1 + 0xc0);
  puVar9[0x14] = 1;
  *(undefined4 *)(puVar9 + 0xd) = 0;
  *(undefined4 *)(puVar9 + 0x10) = 0;
  puVar9[0x11] = 0;
  puVar9[10] = 0;
  puVar9[0xb] = uVar5;
  puVar9[0xc] = 0;
  *(undefined1 (*) [16])(puVar9 + 6) = (undefined1  [16])0x0;
  if (iVar1 != 0) {
    uVar8 = FUN_23e91c140(param_1);
  }
  puVar9[0xf] = uVar8;
  puVar9[0xe] = 0;
  *(int *)(puVar9 + 0x12) = DAT_23ed91748;
  DAT_23ed91748 = DAT_23ed91748 + 1;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  uVar5 = puVar9[-1];
  puVar4 = *(undefined8 **)(lVar2 + 8);
  *puVar4 = puVar9 + -2;
  puVar9[-2] = lVar2;
  puVar9[-1] = (ulonglong)((uint)uVar5 & 3) | (ulonglong)puVar4;
  *(undefined8 **)(lVar2 + 8) = puVar9 + -2;
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  return puVar9;
}
