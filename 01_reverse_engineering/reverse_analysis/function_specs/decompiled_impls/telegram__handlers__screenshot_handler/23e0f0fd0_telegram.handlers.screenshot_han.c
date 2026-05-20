/* ===== 23e0f0fd0 telegram.handlers.screenshot_han:33 ===== */
/* ghidra_name=FUN_23e0f0fd0 entry=23e0f0fd0 size=406 */

undefined8 * FUN_23e0f0fd0(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  
  uVar7 = DAT_23eeaaf50;
  uVar5 = DAT_23eeaaf38;
  plVar6 = DAT_23eea88e8;
  puVar8 = DAT_23ed91750;
  if (DAT_23ed91750 == (undefined8 *)0x0) {
    puVar8 = (undefined8 *)FUN_23e916a20(&DAT_23ec10a80,0x1a);
  }
  else {
    puVar3 = (undefined8 *)*DAT_23ed91750;
    DAT_23ed9174c = DAT_23ed9174c + -1;
    plVar1 = DAT_23ed91750 + 2;
    DAT_23ed91750 = puVar3;
    if (*plVar1 < 0x1a) {
      puVar8 = (undefined8 *)_PyObject_GC_Resize(puVar8,0x1a);
    }
    *puVar8 = 1;
  }
  puVar8[3] = plVar6;
  puVar8[4] = uVar7;
  puVar8[0x13] = puVar8 + 0x15;
  puVar8[9] = FUN_23e1402f0;
  lVar4 = *plVar6;
  puVar8[5] = plVar6;
  *plVar6 = lVar4 + 2;
  uVar7 = 0;
  puVar8[8] = 0;
  iVar2 = *(int *)(param_1 + 0xc0);
  puVar8[0x14] = 0;
  *(undefined4 *)(puVar8 + 0xd) = 0;
  *(undefined4 *)(puVar8 + 0x10) = 0;
  puVar8[0x11] = 0;
  puVar8[10] = 0;
  puVar8[0xb] = uVar5;
  puVar8[0xc] = 0;
  *(undefined1 (*) [16])(puVar8 + 6) = (undefined1  [16])0x0;
  if (iVar2 != 0) {
    uVar7 = FUN_23e91c140(param_1);
  }
  puVar8[0xf] = uVar7;
  puVar8[0xe] = 0;
  *(int *)(puVar8 + 0x12) = DAT_23ed91748;
  DAT_23ed91748 = DAT_23ed91748 + 1;
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
  uVar5 = puVar8[-1];
  puVar3 = *(undefined8 **)(lVar4 + 8);
  *puVar3 = puVar8 + -2;
  puVar8[-2] = lVar4;
  puVar8[-1] = (ulonglong)((uint)uVar5 & 3) | (ulonglong)puVar3;
  *(undefined8 **)(lVar4 + 8) = puVar8 + -2;
  return puVar8;
}
