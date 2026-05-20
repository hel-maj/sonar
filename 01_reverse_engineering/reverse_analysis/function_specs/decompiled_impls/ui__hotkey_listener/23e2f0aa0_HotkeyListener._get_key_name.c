/* ===== 23e2f0aa0 ui.hotkey_listener:c509 ===== */
/* ghidra_name=FUN_23e2f0aa0 entry=23e2f0aa0 size=1382 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e2f0aa0(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  int iVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 local_58;
  undefined8 local_50;
  longlong *local_48;
  
  plVar6 = _DAT_23eeb00b8;
  if (_DAT_23eeb00b8 == (longlong *)0x0) {
LAB_23e2f0ad5:
    _DAT_23eeb00b8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb00b0,DAT_23eeb0170,0);
  }
  else {
    lVar7 = *_DAT_23eeb00b8;
    if (1 < lVar7) {
      *_DAT_23eeb00b8 = lVar7 + -1;
      goto LAB_23e2f0ad5;
    }
    if (_DAT_23eeb00b8[2] != 0) {
      *_DAT_23eeb00b8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e2f0ad5;
    }
  }
  plVar2 = _DAT_23eeb00b8;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeb00b8 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  _DAT_23eeb00b8[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  pcVar5 = (code *)FUN_23e8f5d70();
  if (pcVar5 == (code *)0x0) {
    uVar12 = 0xab;
    FUN_23e915740(param_1,&local_58,_DAT_23eead288);
    plVar6 = local_48;
    uVar10 = local_58;
    uVar11 = local_50;
    goto LAB_23e2f0ce9;
  }
  if (pcVar5 == _Py_NoneStruct_exref) {
    lVar7 = *(longlong *)(DAT_23eead080 + 0x20);
    if (*(char *)(lVar7 + 10) == '\0') {
      plVar6 = (longlong *)FUN_23a37a020(DAT_23eead080,_DAT_23eead290);
      if (plVar6 == (longlong *)0x0) goto LAB_23e2f0eb0;
      lVar7 = *plVar6;
LAB_23e2f0ea4:
      if (lVar7 == 0) goto LAB_23e2f0eb0;
    }
    else {
      iVar4 = *(int *)(lVar7 + 0xc);
      if (*(int *)(lVar7 + 0xc) == 0) {
        *(int *)(lVar7 + 0xc) = DAT_23ec14e3c;
        iVar4 = DAT_23ec14e3c;
        DAT_23ec14e3c = DAT_23ec14e3c + 1;
      }
      if (_DAT_23ec14e30 != iVar4) {
        _DAT_23ec14e30 = iVar4;
        _DAT_23eeb00a8 = FUN_23e8cbd60(lVar7,_DAT_23eead290,*(undefined8 *)(_DAT_23eead290 + 0x18));
      }
      if (-1 < _DAT_23eeb00a8) {
        lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
        if (*(longlong *)(lVar1 + 8 + _DAT_23eeb00a8 * 0x10) != 0) goto LAB_23e2f0c8d;
        _DAT_23eeb00a8 = FUN_23e8cbd60(lVar7,_DAT_23eead290,*(undefined8 *)(_DAT_23eead290 + 0x18));
        if (-1 < _DAT_23eeb00a8) {
          lVar7 = *(longlong *)(lVar1 + 8 + _DAT_23eeb00a8 * 0x10);
          goto LAB_23e2f0ea4;
        }
      }
LAB_23e2f0eb0:
      plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eead290);
      if ((plVar6 == (longlong *)0x0) || (*plVar6 == 0)) {
        uVar12 = 0xac;
        FUN_23e915740(param_1,&local_58,_DAT_23eead290);
        plVar6 = local_48;
        uVar10 = local_58;
        uVar11 = local_50;
        goto LAB_23e2f0ce9;
      }
    }
LAB_23e2f0c8d:
    *(undefined4 *)(plVar2 + 5) = 0xac;
    lVar7 = FUN_23e91a870(param_1);
    if (lVar7 == 0) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = 0xac;
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e2f0ce9;
    }
    FUN_23a3881f0(DAT_23eead080,_DAT_23eead288,lVar7);
  }
  plVar6 = (longlong *)FUN_23e8f5d70();
  if (plVar6 != (longlong *)0x0) {
    *plVar6 = *plVar6 + 1;
    lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar2 = *(longlong **)(lVar7 + 0x28);
    plVar8 = (longlong *)plVar2[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
    *(undefined4 *)(plVar2 + 8) = 0xffffffff;
    if (plVar8 != (longlong *)0x0) {
      plVar2[2] = 0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    plVar2[0xf] = 0;
    return plVar6;
  }
  uVar12 = 0xad;
  FUN_23e915740(param_1,&local_58,_DAT_23eead288);
  plVar6 = local_48;
  uVar10 = local_58;
  uVar11 = local_50;
LAB_23e2f0ce9:
  plVar8 = DAT_23ed6a4f8;
  if (plVar6 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar12;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar1 = plVar8[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar8 + -2;
    plVar8[-2] = lVar7;
    plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar8 + -2;
    plVar9 = plVar8;
  }
  else {
    plVar9 = plVar6;
    if ((longlong *)plVar6[3] != plVar2) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar12;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar1 = plVar8[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar8 + -2;
      plVar8[-2] = lVar7;
      plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar6;
      *(longlong **)(lVar7 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar6;
      plVar9 = plVar8;
      if (lVar1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
    }
  }
  FUN_23e8bba40(plVar2,0);
  if (_DAT_23eeb00b8 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeb00b8 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar7 + 0x28);
  plVar2 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar9);
  return (longlong *)0x0;
}
