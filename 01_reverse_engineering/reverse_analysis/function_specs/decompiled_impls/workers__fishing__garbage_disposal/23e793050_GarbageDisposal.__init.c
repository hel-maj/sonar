/* ===== 23e793050 workers.fishing.garbage_disposal:156 ===== */
/* ghidra_name=FUN_23e793050 entry=23e793050 size=2474 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e793050(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  int iVar12;
  longlong lVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eedac80;
  plVar2 = (longlong *)*param_3;
  if (_DAT_23eedac80 == (longlong *)0x0) {
LAB_23e79308a:
    _DAT_23eedac80 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac78,DAT_23eedacf8,8);
  }
  else {
    lVar14 = *_DAT_23eedac80;
    if (1 < lVar14) {
      *_DAT_23eedac80 = lVar14 + -1;
      goto LAB_23e79308a;
    }
    if (_DAT_23eedac80[2] != 0) {
      *_DAT_23eedac80 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e79308a;
    }
  }
  plVar3 = _DAT_23eedac80;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedac80 + 9;
  lVar13 = *(longlong *)(lVar14 + 8);
  _DAT_23eedac80[0xf] = lVar13;
  *(longlong **)(lVar14 + 8) = plVar9;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar13 = DAT_23eed8080;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar14 = *(longlong *)(lVar13 + 0x20);
  if (*(char *)(lVar14 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(lVar13,DAT_23eed8298);
    if (plVar9 == (longlong *)0x0) goto LAB_23e7934b9;
    lVar13 = *plVar9;
LAB_23e793818:
    if (lVar13 == 0) goto LAB_23e7934b9;
  }
  else {
    iVar12 = *(int *)(lVar14 + 0xc);
    if (*(int *)(lVar14 + 0xc) == 0) {
      *(int *)(lVar14 + 0xc) = _DAT_23ec15418;
      iVar12 = _DAT_23ec15418;
      _DAT_23ec15418 = _DAT_23ec15418 + 1;
    }
    if (_DAT_23ec15408 != iVar12) {
      _DAT_23ec15408 = iVar12;
      _DAT_23eedac68 = FUN_23e8cbd60(lVar14,DAT_23eed8298,*(undefined8 *)(DAT_23eed8298 + 0x18));
    }
    if (-1 < _DAT_23eedac68) {
      lVar1 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
      lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23eedac68 * 0x10);
      if (lVar13 != 0) goto LAB_23e79317a;
      _DAT_23eedac68 = FUN_23e8cbd60(lVar14,DAT_23eed8298,*(undefined8 *)(DAT_23eed8298 + 0x18));
      if (-1 < _DAT_23eedac68) {
        lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23eedac68 * 0x10);
        goto LAB_23e793818;
      }
    }
LAB_23e7934b9:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed8298);
    if ((plVar9 == (longlong *)0x0) || (lVar13 = *plVar9, lVar13 == 0)) {
      uVar15 = 0x9d;
      FUN_23e915740(param_1,&uStack_68,DAT_23eed8298);
      plVar9 = plStack_58;
      uVar6 = uStack_68;
      uVar5 = uStack_60;
      plVar10 = DAT_23ed6a4f8;
      goto joined_r0x00023e793605;
    }
  }
LAB_23e79317a:
  *(undefined4 *)(plVar3 + 5) = 0x9d;
  plVar9 = (longlong *)FUN_23e94bb80(param_1,lVar13,DAT_23eed82a0);
  if (plVar9 != (longlong *)0x0) {
    cVar8 = FUN_23e8d9ac0(plVar2,DAT_23eed82a8,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    pcVar7 = _Py_NoneStruct_exref;
    if (cVar8 != '\0') {
      cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eed82b0,_Py_NoneStruct_exref);
      if (cVar8 == '\0') {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x9e;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023e793605;
      }
      cVar8 = FUN_23e8d9ac0(plVar2,DAT_23eed82b8,pcVar7);
      lVar14 = DAT_23ed6cce8;
      if (cVar8 == '\0') {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x9f;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023e793605;
      }
      lVar13 = *(longlong *)(param_1 + 0x10);
      iVar12 = *(int *)(lVar13 + 0x1410);
      plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
      *plVar9 = *plVar9 + 1;
      if (iVar12 == 0) {
        plVar10 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
        plVar9 = *(longlong **)(lVar14 + 0x20);
      }
      else {
        iVar12 = iVar12 + -1;
        *(int *)(lVar13 + 0x1410) = iVar12;
        plVar10 = *(longlong **)(lVar13 + 0x1190 + (longlong)iVar12 * 8);
        *plVar10 = 1;
      }
      lVar14 = *(longlong *)(lVar14 + 0x28);
      plVar10[2] = 0;
      plVar10[3] = 1;
      plVar10[4] = (longlong)plVar9;
      plVar10[5] = lVar14;
      cVar8 = FUN_23e8d9ac0(plVar2,DAT_23eed82c0,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (cVar8 == '\0') {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0xa0;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023e793605;
      }
      lVar14 = *(longlong *)(DAT_23eed8080 + 0x20);
      if (*(char *)(lVar14 + 10) == '\0') {
        plVar9 = (longlong *)FUN_23a37a020(DAT_23eed8080,DAT_23eed82c8);
        if (plVar9 == (longlong *)0x0) goto LAB_23e7938f0;
        lVar14 = *plVar9;
LAB_23e7938dc:
        if (lVar14 == 0) goto LAB_23e7938f0;
      }
      else {
        iVar12 = *(int *)(lVar14 + 0xc);
        if (*(int *)(lVar14 + 0xc) == 0) {
          *(int *)(lVar14 + 0xc) = _DAT_23ec15418;
          iVar12 = _DAT_23ec15418;
          _DAT_23ec15418 = _DAT_23ec15418 + 1;
        }
        if (_DAT_23ec1540c != iVar12) {
          _DAT_23ec1540c = iVar12;
          _DAT_23eedac70 = FUN_23e8cbd60(lVar14,DAT_23eed82c8,*(undefined8 *)(DAT_23eed82c8 + 0x18))
          ;
        }
        if (-1 < _DAT_23eedac70) {
          lVar13 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
          if (*(longlong *)(lVar13 + 8 + _DAT_23eedac70 * 0x10) != 0) goto LAB_23e79330d;
          _DAT_23eedac70 = FUN_23e8cbd60(lVar14,DAT_23eed82c8,*(undefined8 *)(DAT_23eed82c8 + 0x18))
          ;
          if (-1 < _DAT_23eedac70) {
            lVar14 = *(longlong *)(lVar13 + 8 + _DAT_23eedac70 * 0x10);
            goto LAB_23e7938dc;
          }
        }
LAB_23e7938f0:
        plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed82c8);
        if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
          uVar15 = 0xa1;
          FUN_23e915740(param_1,&uStack_68,DAT_23eed82c8);
          plVar9 = plStack_58;
          uVar6 = uStack_68;
          uVar5 = uStack_60;
          plVar10 = DAT_23ed6a4f8;
          goto joined_r0x00023e793605;
        }
      }
LAB_23e79330d:
      *(undefined4 *)(plVar3 + 5) = 0xa1;
      plVar9 = (longlong *)FUN_23e91a870(param_1);
      if (plVar9 != (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23e8c6f80(plVar9,_DAT_23eed82d0);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar10 != (longlong *)0x0) {
          cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eed82d8,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (cVar8 != '\0') {
            plVar9 = (longlong *)FUN_23e8d7870(param_1,_DAT_23eed82e0);
            cVar8 = FUN_23e8d9ac0(plVar2,DAT_23eed82e8,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (cVar8 == '\0') {
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar15 = 0xa4;
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar10 = DAT_23ed6a4f8;
            }
            else {
              cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eed82f8,_DAT_23eed82f0);
              if (cVar8 == '\0') {
                uVar6 = *(undefined8 *)(param_1 + 0x60);
                uVar15 = 0xab;
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar5 = *(undefined8 *)(param_1 + 0x68);
                plVar10 = DAT_23ed6a4f8;
              }
              else {
                plVar9 = (longlong *)FUN_23e8d7870(param_1,_DAT_23eed8300);
                cVar8 = FUN_23e8d9ac0(plVar2,DAT_23eed8308,plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (cVar8 != '\0') {
                  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar9 = *(longlong **)(lVar14 + 0x28);
                  plVar3 = (longlong *)plVar9[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar14 + 0x30);
                  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                  if (plVar3 != (longlong *)0x0) {
                    plVar9[2] = 0;
                    *plVar3 = *plVar3 + -1;
                    if (*plVar3 == 0) {
                      (**(code **)(plVar3[1] + 0x30))();
                    }
                  }
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                  plVar9[0xf] = 0;
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 != 0) {
                    return pcVar7;
                  }
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                  return pcVar7;
                }
                uVar6 = *(undefined8 *)(param_1 + 0x60);
                uVar15 = 0xae;
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar5 = *(undefined8 *)(param_1 + 0x68);
                plVar10 = DAT_23ed6a4f8;
              }
            }
            goto joined_r0x00023e793605;
          }
        }
      }
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar15 = 0xa1;
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = DAT_23ed6a4f8;
      goto joined_r0x00023e793605;
    }
  }
  plVar9 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = 0x9d;
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
joined_r0x00023e793605:
  DAT_23ed6a4f8 = plVar10;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar10;
    }
    pcVar7 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar13 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar14 + 8);
    *puVar4 = plVar11 + -2;
    plVar11[-2] = lVar14;
    plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar14 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar9;
    if ((longlong *)plVar9[3] != plVar3) {
      if (plVar10 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar10;
      }
      pcVar7 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar14 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      lVar13 = plVar11[-1];
      puVar4 = *(undefined8 **)(lVar14 + 8);
      *puVar4 = plVar11 + -2;
      plVar11[-2] = lVar14;
      plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4;
      lVar13 = *plVar9;
      *(longlong **)(lVar14 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      if (lVar13 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5dc90,plVar2);
  if (_DAT_23eedac80 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedac80 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar14 + 0x28);
  plVar3 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar6,uVar5,plVar11);
  return (code *)0x0;
}
