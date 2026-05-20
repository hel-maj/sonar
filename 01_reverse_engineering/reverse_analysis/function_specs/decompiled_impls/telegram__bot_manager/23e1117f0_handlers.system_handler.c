/* ===== 23e1117f0 telegram.bot_manager:99 ===== */
/* ghidra_name=FUN_23e1117f0 entry=23e1117f0 size=641 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e1117f0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong *plVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  
  plVar10 = DAT_23ed6a4e0;
  lVar7 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar10 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar12 = *plVar10 + 1;
  }
  else {
    lVar12 = 2;
    plVar11 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar11;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar11 = _DAT_23eea99b0;
  plVar10[2] = lVar7;
  uVar8 = DAT_23eeab470;
  uVar4 = DAT_23eeab410;
  plVar5 = _DAT_23eea9a88;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar10[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar10 + -2;
  puVar9 = DAT_23ed91750;
  plVar10[-2] = lVar7;
  plVar10[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar10 + -2;
  *plVar10 = lVar12;
  if (puVar9 == (undefined8 *)0x0) {
    puVar9 = (undefined8 *)FUN_23e916a20(&DAT_23ec10a80,0x9c);
  }
  else {
    DAT_23ed91750 = (undefined8 *)*puVar9;
    DAT_23ed9174c = DAT_23ed9174c + -1;
    if ((longlong)puVar9[2] < 0x9c) {
      puVar9 = (undefined8 *)_PyObject_GC_Resize(puVar9,0x9c);
    }
    *puVar9 = 1;
  }
  puVar9[3] = plVar11;
  puVar9[4] = uVar8;
  puVar9[0x13] = puVar9 + 0x16;
  puVar9[9] = FUN_23e13a660;
  lVar7 = *plVar11 + 1;
  *plVar11 = lVar7;
  if (plVar5 != (longlong *)0x0) {
    lVar7 = *plVar5;
    plVar11 = plVar5;
  }
  puVar9[5] = plVar11;
  *plVar11 = lVar7 + 1;
  uVar8 = 0;
  puVar9[0x15] = plVar10;
  puVar9[8] = 0;
  iVar1 = *(int *)(param_1 + 0xc0);
  puVar9[6] = 0;
  puVar9[0x14] = 1;
  puVar9[7] = 0;
  *(undefined4 *)(puVar9 + 0xd) = 0;
  *(undefined4 *)(puVar9 + 0x10) = 0;
  puVar9[0x11] = 0;
  puVar9[10] = 0;
  puVar9[0xb] = uVar4;
  puVar9[0xc] = 0;
  if (iVar1 != 0) {
    uVar8 = FUN_23e91c140(param_1);
  }
  puVar9[0xf] = uVar8;
  puVar9[0xe] = 0;
  *(int *)(puVar9 + 0x12) = DAT_23ed91748;
  DAT_23ed91748 = DAT_23ed91748 + 1;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  uVar4 = puVar9[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = puVar9 + -2;
  puVar9[-2] = lVar7;
  puVar9[-1] = (ulonglong)((uint)uVar4 & 3) | (ulonglong)puVar3;
  *(undefined8 **)(lVar7 + 8) = puVar9 + -2;
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  return puVar9;
}
