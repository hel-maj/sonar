/* ===== 23c6218f0 license.hwid_generator:c397 ===== */
/* ghidra_name=FUN_23c6218f0 entry=23c6218f0 size=1665 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23c6218f0(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 local_58;
  undefined8 local_50;
  longlong *local_48;
  
  plVar8 = _DAT_23ee29d50;
  if (_DAT_23ee29d50 == (longlong *)0x0) {
LAB_23c621925:
    _DAT_23ee29d50 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29d48,_DAT_23ee29d98,0);
  }
  else {
    lVar7 = *_DAT_23ee29d50;
    if (1 < lVar7) {
      *_DAT_23ee29d50 = lVar7 + -1;
      goto LAB_23c621925;
    }
    if (_DAT_23ee29d50[2] != 0) {
      *_DAT_23ee29d50 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23c621925;
    }
  }
  plVar2 = _DAT_23ee29d50;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23ee29d50 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  _DAT_23ee29d50[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar8;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar10 = _DAT_23ee28eb8;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar7 = FUN_23ead6330();
  if (lVar7 == 0) {
    uVar12 = 0x9b;
    FUN_23e915740(param_1,&local_58,_DAT_23ee28e38);
    plVar8 = local_48;
    uVar10 = local_58;
    uVar11 = local_50;
    plVar4 = DAT_23ed6a4f8;
    goto joined_r0x00023c621c43;
  }
  *(undefined4 *)(plVar2 + 5) = 0x9b;
  plVar8 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plVar8 == (longlong *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x70);
    uVar10 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar12 = 0x9b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    plVar4 = DAT_23ed6a4f8;
    goto joined_r0x00023c621c43;
  }
  plVar9 = (longlong *)_PyDict_NewPresized(3);
  PyDict_SetItem(plVar9,uVar10,plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  uVar10 = _DAT_23ee28ec0;
  lVar7 = FUN_23ead61e0();
  if (lVar7 == 0) {
    uVar12 = 0x9c;
    FUN_23e915740(param_1,&local_58,_DAT_23ee28e40);
    plVar8 = local_48;
    uVar10 = local_58;
    uVar11 = local_50;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x9c;
    plVar8 = (longlong *)FUN_23e91a870(param_1,lVar7);
    if (plVar8 == (longlong *)0x0) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = 0x9c;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      PyDict_SetItem(plVar9,uVar10,plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      uVar10 = _DAT_23ee28ec8;
      lVar7 = *(longlong *)(DAT_23ee28c48 + 0x20);
      if (*(char *)(lVar7 + 10) == '\0') {
        plVar8 = (longlong *)FUN_23a37a020(DAT_23ee28c48,_DAT_23ee28ed0);
        if (plVar8 == (longlong *)0x0) goto LAB_23c621bd9;
        lVar7 = *plVar8;
LAB_23c621f48:
        if (lVar7 == 0) goto LAB_23c621bd9;
      }
      else {
        iVar6 = *(int *)(lVar7 + 0xc);
        if (*(int *)(lVar7 + 0xc) == 0) {
          *(int *)(lVar7 + 0xc) = DAT_23ec12b10;
          iVar6 = DAT_23ec12b10;
          DAT_23ec12b10 = DAT_23ec12b10 + 1;
        }
        if (_DAT_23ec12b0c != iVar6) {
          _DAT_23ec12b0c = iVar6;
          _DAT_23ee29d40 =
               FUN_23e8cbd60(lVar7,_DAT_23ee28ed0,*(undefined8 *)(_DAT_23ee28ed0 + 0x18));
        }
        if (-1 < _DAT_23ee29d40) {
          lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
          if (*(longlong *)(lVar1 + 8 + _DAT_23ee29d40 * 0x10) != 0) goto LAB_23c621ac2;
          _DAT_23ee29d40 =
               FUN_23e8cbd60(lVar7,_DAT_23ee28ed0,*(undefined8 *)(_DAT_23ee28ed0 + 0x18));
          if (-1 < _DAT_23ee29d40) {
            lVar7 = *(longlong *)(lVar1 + 8 + _DAT_23ee29d40 * 0x10);
            goto LAB_23c621f48;
          }
        }
LAB_23c621bd9:
        plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ee28ed0);
        if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
          uVar12 = 0x9d;
          FUN_23e915740(param_1,&local_58,_DAT_23ee28ed0);
          plVar8 = local_48;
          uVar10 = local_58;
          uVar11 = local_50;
          goto LAB_23c621c30;
        }
      }
LAB_23c621ac2:
      *(undefined4 *)(plVar2 + 5) = 0x9d;
      plVar8 = (longlong *)FUN_23e91a870(param_1);
      if (plVar8 != (longlong *)0x0) {
        PyDict_SetItem(plVar9,uVar10,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar7 + 0x28);
        plVar2 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar2 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        return plVar9;
      }
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = 0x9d;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
    }
  }
LAB_23c621c30:
  *plVar9 = *plVar9 + -1;
  plVar4 = DAT_23ed6a4f8;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
    plVar4 = DAT_23ed6a4f8;
  }
joined_r0x00023c621c43:
  DAT_23ed6a4f8 = plVar4;
  if (plVar8 == (longlong *)0x0) {
    if (plVar4 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar4;
      *plVar4 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar9 = plVar4;
    }
    pcVar5 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar1 = plVar9[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar9 + -2;
    plVar9[-2] = lVar7;
    plVar9[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar9 + -2;
  }
  else {
    plVar9 = plVar8;
    if ((longlong *)plVar8[3] != plVar2) {
      if (plVar4 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar4;
        *plVar4 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar9 = plVar4;
      }
      pcVar5 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar1 = plVar9[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar9 + -2;
      plVar9[-2] = lVar7;
      plVar9[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar8;
      *(longlong **)(lVar7 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar8;
      if (lVar1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar2,0);
  if (_DAT_23ee29d50 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23ee29d50 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar2 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar9);
  return (longlong *)0x0;
}
