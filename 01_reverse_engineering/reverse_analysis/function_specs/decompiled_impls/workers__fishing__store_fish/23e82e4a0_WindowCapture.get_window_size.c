/* ===== 23e82e4a0 workers.fishing.store_fish:155 ===== */
/* ghidra_name=FUN_23e82e4a0 entry=23e82e4a0 size=2260 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e82e4a0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  code *pcVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong lVar15;
  undefined4 uVar16;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar12 = _DAT_23eede690;
  plVar2 = (longlong *)*param_3;
  if (_DAT_23eede690 == (longlong *)0x0) {
LAB_23e82e4da:
    _DAT_23eede690 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede688,DAT_23eede708,8);
  }
  else {
    lVar15 = *_DAT_23eede690;
    if (1 < lVar15) {
      *_DAT_23eede690 = lVar15 + -1;
      goto LAB_23e82e4da;
    }
    if (_DAT_23eede690[2] != 0) {
      *_DAT_23eede690 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e82e4da;
    }
  }
  plVar4 = _DAT_23eede690;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eede690 + 9;
  lVar14 = *(longlong *)(lVar15 + 8);
  _DAT_23eede690[0xf] = lVar14;
  *(longlong **)(lVar15 + 8) = plVar12;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  lVar14 = DAT_23eedc7f0;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar15 = *(longlong *)(lVar14 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(lVar14,_DAT_23eedca00);
    if (plVar12 == (longlong *)0x0) goto LAB_23e82e889;
    lVar14 = *plVar12;
LAB_23e82ebd8:
    if (lVar14 == 0) goto LAB_23e82e889;
  }
  else {
    iVar11 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec1555c;
      iVar11 = DAT_23ec1555c;
      DAT_23ec1555c = DAT_23ec1555c + 1;
    }
    if (_DAT_23ec1554c != iVar11) {
      _DAT_23ec1554c = iVar11;
      _DAT_23eede678 = FUN_23e8cbd60(lVar15,_DAT_23eedca00,*(undefined8 *)(_DAT_23eedca00 + 0x18));
    }
    if (-1 < _DAT_23eede678) {
      lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eede678 * 0x10);
      if (lVar14 != 0) goto LAB_23e82e5ca;
      _DAT_23eede678 = FUN_23e8cbd60(lVar15,_DAT_23eedca00,*(undefined8 *)(_DAT_23eedca00 + 0x18));
      if (-1 < _DAT_23eede678) {
        lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eede678 * 0x10);
        goto LAB_23e82ebd8;
      }
    }
LAB_23e82e889:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedca00);
    if ((plVar12 == (longlong *)0x0) || (lVar14 = *plVar12, lVar14 == 0)) {
      uVar16 = 0x9c;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eedca00);
      plVar12 = plStack_58;
      uVar5 = uStack_68;
      uVar6 = uStack_60;
      plVar7 = DAT_23ed6a4f8;
      goto joined_r0x00023e82e9d5;
    }
  }
LAB_23e82e5ca:
  *(undefined4 *)(plVar4 + 5) = 0x9c;
  plVar12 = (longlong *)FUN_23e94bb80(param_1,lVar14,_DAT_23eedca08);
  if (plVar12 != (longlong *)0x0) {
    cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eedca10,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    pcVar8 = _Py_NoneStruct_exref;
    if (cVar10 != '\0') {
      cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eedca18,_Py_NoneStruct_exref);
      if (cVar10 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar16 = 0x9d;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
        goto joined_r0x00023e82e9d5;
      }
      cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eedca20,pcVar8);
      if (cVar10 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar16 = 0x9e;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
        goto joined_r0x00023e82e9d5;
      }
      lVar15 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar15 + 0x1188) == 0) {
        plVar12 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar11 = *(int *)(lVar15 + 0x1188) + -1;
        *(int *)(lVar15 + 0x1188) = iVar11;
        plVar12 = *(longlong **)(lVar15 + 0xf08 + (longlong)iVar11 * 8);
        *plVar12 = 1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar12[2] = 0;
      plVar12[4] = 0;
      plVar12[3] = 0;
      lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar14 = plVar12[-1];
      puVar3 = *(undefined8 **)(lVar15 + 8);
      *puVar3 = plVar12 + -2;
      plVar12[-2] = lVar15;
      plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar15 + 8) = plVar12 + -2;
      cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedca28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (cVar10 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar16 = 0x9f;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
        goto joined_r0x00023e82e9d5;
      }
      cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedca30,pcVar8);
      if (cVar10 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar16 = 0xa0;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
        goto joined_r0x00023e82e9d5;
      }
      lVar15 = *(longlong *)(DAT_23eedc7f0 + 0x20);
      if (*(char *)(lVar15 + 10) == '\0') {
        plVar12 = (longlong *)FUN_23a37a020(DAT_23eedc7f0,_DAT_23eedca38);
        if (plVar12 == (longlong *)0x0) goto LAB_23e82ed10;
        lVar15 = *plVar12;
LAB_23e82ecfc:
        if (lVar15 == 0) goto LAB_23e82ed10;
      }
      else {
        iVar11 = *(int *)(lVar15 + 0xc);
        if (*(int *)(lVar15 + 0xc) == 0) {
          *(int *)(lVar15 + 0xc) = DAT_23ec1555c;
          iVar11 = DAT_23ec1555c;
          DAT_23ec1555c = DAT_23ec1555c + 1;
        }
        if (_DAT_23ec15550 != iVar11) {
          _DAT_23ec15550 = iVar11;
          _DAT_23eede680 =
               FUN_23e8cbd60(lVar15,_DAT_23eedca38,*(undefined8 *)(_DAT_23eedca38 + 0x18));
        }
        if (-1 < _DAT_23eede680) {
          lVar14 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
          if (*(longlong *)(lVar14 + 8 + _DAT_23eede680 * 0x10) != 0) goto LAB_23e82e7a5;
          _DAT_23eede680 =
               FUN_23e8cbd60(lVar15,_DAT_23eedca38,*(undefined8 *)(_DAT_23eedca38 + 0x18));
          if (-1 < _DAT_23eede680) {
            lVar15 = *(longlong *)(lVar14 + 8 + _DAT_23eede680 * 0x10);
            goto LAB_23e82ecfc;
          }
        }
LAB_23e82ed10:
        plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedca38);
        if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
          uVar16 = 0xa1;
          FUN_23e915740(param_1,&uStack_68,_DAT_23eedca38);
          plVar12 = plStack_58;
          uVar5 = uStack_68;
          uVar6 = uStack_60;
          plVar7 = DAT_23ed6a4f8;
          goto joined_r0x00023e82e9d5;
        }
      }
LAB_23e82e7a5:
      *(undefined4 *)(plVar4 + 5) = 0xa1;
      plVar12 = (longlong *)FUN_23e91a870(param_1);
      if (plVar12 != (longlong *)0x0) {
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedca40,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (cVar10 != '\0') {
          lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar12 = *(longlong **)(lVar15 + 0x28);
          plVar4 = (longlong *)plVar12[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
          *(undefined4 *)(plVar12 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar12[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          *(longlong *)pcVar8 = *(longlong *)pcVar8 + 1;
          plVar12[0xf] = 0;
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar8;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar8;
        }
      }
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      uVar16 = 0xa1;
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      plVar7 = DAT_23ed6a4f8;
      goto joined_r0x00023e82e9d5;
    }
  }
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar16 = 0x9c;
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar7 = DAT_23ed6a4f8;
joined_r0x00023e82e9d5:
  DAT_23ed6a4f8 = plVar7;
  if (plVar12 == (longlong *)0x0) {
    if (plVar7 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar7;
      *plVar7 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar7;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar15 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar14 = plVar13[-1];
    puVar3 = *(undefined8 **)(lVar15 + 8);
    *puVar3 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar12;
    if ((longlong *)plVar12[3] != plVar4) {
      if (plVar7 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar7;
        *plVar7 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar7;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar15 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
      lVar14 = plVar13[-1];
      puVar3 = *(undefined8 **)(lVar15 + 8);
      *puVar3 = plVar13 + -2;
      plVar13[-2] = lVar15;
      plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
      lVar14 = *plVar12;
      *(longlong **)(lVar15 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar12;
      if (lVar14 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e2bc,plVar2);
  if (_DAT_23eede690 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede690 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar15 + 0x28);
  plVar4 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar13);
  return (code *)0x0;
}
