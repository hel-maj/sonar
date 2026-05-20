/* ===== 23e7e2d00 workers.fishing.memory_fish_read:71 ===== */
/* ghidra_name=FUN_23e7e2d00 entry=23e7e2d00 size=535 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e7e2d00(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  longlong lVar10;
  
  plVar9 = DAT_23ed6a4e0;
  lVar1 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar10 = *plVar9 + 1;
  }
  else {
    lVar10 = 2;
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar7 = _DAT_23eeddce0;
  plVar9[2] = lVar1;
  uVar4 = DAT_23eedebc0;
  uVar5 = _DAT_23eedeb80;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar9[-1];
  puVar3 = *(undefined8 **)(lVar1 + 8);
  *puVar3 = plVar9 + -2;
  puVar8 = DAT_23ed709b8;
  plVar9[-2] = lVar1;
  plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar1 + 8) = plVar9 + -2;
  *plVar9 = lVar10;
  if (puVar8 == (undefined8 *)0x0) {
    puVar8 = (undefined8 *)FUN_23e916a20(&DAT_23ec0fd00,0x8c);
  }
  else {
    DAT_23ed709b8 = (undefined8 *)*puVar8;
    DAT_23ed709b4 = DAT_23ed709b4 + -1;
    if ((longlong)puVar8[2] < 0x8c) {
      puVar8 = (undefined8 *)_PyObject_GC_Resize(puVar8,0x8c);
    }
    *puVar8 = 1;
  }
  puVar8[3] = plVar7;
  puVar8[4] = uVar4;
  puVar8[0x12] = puVar8 + 0x15;
  puVar8[9] = FUN_23e7e2f30;
  lVar1 = *plVar7;
  puVar8[5] = plVar7;
  *plVar7 = lVar1 + 2;
  puVar8[0x14] = plVar9;
  puVar8[0x13] = 1;
  *(int *)(puVar8 + 0x11) = DAT_23ed709b0;
  lVar1 = *(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10);
  DAT_23ed709b0 = DAT_23ed709b0 + 1;
  *(undefined1 (*) [16])(puVar8 + 6) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(puVar8 + 0xd) = (undefined1  [16])0x0;
  lVar1 = *(longlong *)(lVar1 + 0x2e8);
  uVar4 = puVar8[-1];
  *(undefined4 *)(puVar8 + 0xc) = 0;
  *(undefined4 *)(puVar8 + 8) = 0;
  puVar3 = *(undefined8 **)(lVar1 + 8);
  puVar8[0xb] = uVar5;
  *(undefined4 *)(puVar8 + 0xf) = 0;
  puVar8[10] = 0;
  puVar8[0x10] = 0;
  *puVar3 = puVar8 + -2;
  puVar8[-2] = lVar1;
  puVar8[-1] = (ulonglong)((uint)uVar4 & 3) | (ulonglong)puVar3;
  *(undefined8 **)(lVar1 + 8) = puVar8 + -2;
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  return puVar8;
}
