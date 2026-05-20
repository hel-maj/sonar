/* ===== 23e130a70 telegram.notification_manager:94 ===== */
/* ghidra_name=FUN_23e130a70 entry=23e130a70 size=3553 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e130a70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  longlong lVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *local_98;
  longlong *local_90;
  longlong *local_88;
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  
  plVar9 = _DAT_23eeaadb0;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  plVar4 = (longlong *)param_3[2];
  if (_DAT_23eeaadb0 == (longlong *)0x0) {
LAB_23e130abd:
    _DAT_23eeaadb0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaada8,DAT_23eeaae08,0x30);
  }
  else {
    lVar10 = *_DAT_23eeaadb0;
    if (1 < lVar10) {
      *_DAT_23eeaadb0 = lVar10 + -1;
      goto LAB_23e130abd;
    }
    if (_DAT_23eeaadb0[2] != 0) {
      *_DAT_23eeaadb0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e130abd;
    }
  }
  plVar6 = _DAT_23eeaadb0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeaadb0 + 9;
  lVar16 = *(longlong *)(lVar10 + 8);
  _DAT_23eeaadb0[0xf] = lVar16;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar6[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar10 = _DAT_23eea8238;
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  uVar7 = DAT_23eea8230;
  *(undefined4 *)(plVar6 + 5) = 100;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar2,uVar7,*(undefined8 *)(lVar10 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar14 = 100;
    local_90 = *(longlong **)(param_1 + 0x68);
    local_98 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
LAB_23e1310ff:
    plVar12 = DAT_23ed6a4f8;
    if (local_68 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar17 = _PyRuntime_exref;
      plVar12[2] = 0;
      plVar12[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      lVar10 = *(longlong *)(pcVar17 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar16 = plVar12[-1];
      puVar5 = *(undefined8 **)(lVar10 + 8);
      *puVar5 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar11 = plVar12;
      goto LAB_23e1311b3;
    }
    plVar11 = local_68;
    if ((longlong *)local_68[3] == plVar6) goto LAB_23e1311b3;
    plVar19 = local_68;
    if (DAT_23ed6a4f8 == (longlong *)0x0) goto LAB_23e1316c8;
    plVar11 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar11;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  else {
    iVar8 = FUN_23a35f020(plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    pcVar17 = _Py_NoneStruct_exref;
    if (iVar8 == -1) {
      local_88 = *(longlong **)(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar18 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar14 = 100;
      plVar9 = (longlong *)0x0;
      local_90 = *(longlong **)(param_1 + 0x68);
      local_98 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e1310ff;
    }
    if (iVar8 == 0) {
      lVar10 = *(longlong *)(param_1 + 0x38);
      lVar16 = *(longlong *)(lVar10 + 8);
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      plVar9 = *(longlong **)(lVar16 + 0x28);
      plVar6 = (longlong *)plVar9[2];
      *(undefined8 *)(lVar10 + 8) = *(undefined8 *)(lVar16 + 0x30);
      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
      if (plVar6 != (longlong *)0x0) {
        plVar9[2] = 0;
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))();
        }
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plVar9[0xf] = 0;
      goto LAB_23e130f96;
    }
    lVar10 = *(longlong *)(DAT_23eea8118 + 0x20);
    if (*(char *)(lVar10 + 10) == '\0') {
      plVar9 = (longlong *)FUN_23a37a020(DAT_23eea8118,DAT_23eea8240);
      if (plVar9 == (longlong *)0x0) goto LAB_23e131059;
      lVar16 = *plVar9;
LAB_23e131700:
      if (lVar16 == 0) goto LAB_23e131059;
    }
    else {
      iVar8 = *(int *)(lVar10 + 0xc);
      if (*(int *)(lVar10 + 0xc) == 0) {
        *(int *)(lVar10 + 0xc) = DAT_23ec14c1c;
        iVar8 = DAT_23ec14c1c;
        DAT_23ec14c1c = DAT_23ec14c1c + 1;
      }
      if (_DAT_23ec14c18 != iVar8) {
        _DAT_23ec14c18 = iVar8;
        _DAT_23eeaada0 = FUN_23e8cbd60(lVar10,DAT_23eea8240,*(undefined8 *)(DAT_23eea8240 + 0x18));
      }
      if (-1 < _DAT_23eeaada0) {
        lVar1 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
        lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeaada0 * 0x10);
        if (lVar16 != 0) goto LAB_23e130c05;
        _DAT_23eeaada0 = FUN_23e8cbd60(lVar10,DAT_23eea8240,*(undefined8 *)(DAT_23eea8240 + 0x18));
        if (-1 < _DAT_23eeaada0) {
          lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeaada0 * 0x10);
          goto LAB_23e131700;
        }
      }
LAB_23e131059:
      plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8240);
      if ((plVar9 == (longlong *)0x0) || (lVar16 = *plVar9, lVar16 == 0)) {
        plVar18 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        FUN_23e915740(param_1,&local_78,DAT_23eea8240);
        local_98 = (longlong *)0x0;
        uVar14 = 0x68;
        local_88 = local_78;
        local_90 = plStack_70;
        goto LAB_23e1310ff;
      }
    }
LAB_23e130c05:
    *(undefined4 *)(plVar6 + 5) = 0x68;
    plVar9 = (longlong *)FUN_23e914090(param_1,lVar16,plVar3);
    plVar18 = _DAT_23eea8248;
    if (plVar9 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar18 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar14 = 0x68;
      local_90 = *(longlong **)(param_1 + 0x68);
      local_98 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e1310ff;
    }
    lVar10 = *(longlong *)(param_1 + 0x10);
    plVar12 = *(longlong **)(lVar10 + 0xe28);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar16 = plVar12[3];
      *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
      *(longlong *)(lVar10 + 0xe28) = lVar16;
      *plVar12 = 1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar19 = (longlong *)&DAT_23ed6a4c0;
    *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
    lVar16 = plVar12[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar10;
    plVar12[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar12 + -2;
    plVar11 = DAT_23ed6a4c0;
    *plVar18 = *plVar18 + 1;
    plVar12[3] = (longlong)plVar18;
    plVar13 = DAT_23ed6cd28;
    plVar18 = &DAT_23ed6cce0;
    if (plVar11 != (longlong *)0x0) {
LAB_23e130cd3:
      plStack_70 = plVar13;
      local_78 = plVar9;
      lVar10 = FUN_23e94ed00(param_1,plVar11,&local_78);
      if (lVar10 == 0) {
        local_88 = *(longlong **)(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        local_98 = (longlong *)0x0;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      else {
        plVar12[4] = lVar10;
        plVar18 = _DAT_23eea8250;
        *_DAT_23eea8250 = *_DAT_23eea8250 + 1;
        plVar12[5] = (longlong)plVar18;
        local_98 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (local_98 != (longlong *)0x0) {
          iVar8 = FUN_23a35f020(plVar4);
          if (iVar8 == -1) {
            local_88 = *(longlong **)(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            plVar18 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar14 = 0x6c;
            local_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else if (iVar8 == 0) {
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eea8268);
            if (plVar12 != (longlong *)0x0) {
              *(undefined4 *)(plVar6 + 5) = 0x70;
              plVar18 = (longlong *)FUN_23e915840(param_1,plVar2,DAT_23eea8220,local_98);
              if (plVar18 == (longlong *)0x0) {
                local_88 = *(longlong **)(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar14 = 0x70;
                uVar15 = 0x70;
                local_90 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                lVar10 = *plVar12;
                plVar18 = (longlong *)0x0;
joined_r0x00023e13187f:
                if (lVar10 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                  uVar14 = uVar15;
                }
                goto LAB_23e1310ff;
              }
              *(undefined4 *)(plVar6 + 5) = 0x70;
              plVar11 = (longlong *)FUN_23e914090(param_1,plVar12,plVar18);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar18 = *plVar18 + -1;
              if (*plVar18 == 0) {
                (**(code **)(plVar18[1] + 0x30))(plVar18);
              }
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                plVar18 = (longlong *)0x0;
LAB_23e13149c:
                lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar6 = *(longlong **)(lVar10 + 0x28);
                plVar12 = (longlong *)plVar6[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
                *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                if (plVar12 != (longlong *)0x0) {
                  plVar6[2] = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                }
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                plVar6[0xf] = 0;
                pcVar17 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                lVar10 = *local_98;
                *local_98 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  (**(code **)(local_98[1] + 0x30))();
                }
                if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
LAB_23e130f96:
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                *plVar4 = *plVar4 + -1;
                if (*plVar4 != 0) {
                  return pcVar17;
                }
                (**(code **)(plVar4[1] + 0x30))(plVar4);
                return pcVar17;
              }
            }
            local_88 = *(longlong **)(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            plVar18 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar14 = 0x70;
            local_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            lVar10 = FUN_23e8ff7a0();
            if (lVar10 == 0) {
              FUN_23e915740(param_1,&local_78,DAT_23eea8258);
              uVar14 = 0x6d;
              local_88 = local_78;
              local_90 = plStack_70;
              plVar18 = (longlong *)0x0;
            }
            else {
              lVar16 = *(longlong *)(param_1 + 0x10);
              plVar12 = *(longlong **)(lVar16 + 0xe18);
              if (plVar12 == (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
              }
              else {
                lVar1 = plVar12[3];
                *(int *)(lVar16 + 0xeb8) = *(int *)(lVar16 + 0xeb8) + -1;
                *(longlong *)(lVar16 + 0xe18) = lVar1;
                *plVar12 = 1;
              }
              lVar16 = *(longlong *)
                        (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
              lVar1 = plVar12[-1];
              puVar5 = *(undefined8 **)(lVar16 + 8);
              *puVar5 = plVar12 + -2;
              plVar12[-2] = lVar16;
              plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar5;
              *(longlong **)(lVar16 + 8) = plVar12 + -2;
              uVar7 = _DAT_23eea8260;
              *plVar4 = *plVar4 + 1;
              plVar12[3] = (longlong)plVar4;
              plVar11 = (longlong *)FUN_23e8d7870(param_1,uVar7);
              *(undefined4 *)(plVar6 + 5) = 0x6d;
              plVar18 = (longlong *)FUN_23a334c60(param_1,lVar10,plVar12,plVar11);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar18 == (longlong *)0x0) {
                local_88 = *(longlong **)(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar14 = 0x6d;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_90 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eea8268);
                if (plVar12 != (longlong *)0x0) {
                  *(undefined4 *)(plVar6 + 5) = 0x6e;
                  local_78 = local_98;
                  plStack_70 = plVar18;
                  plVar11 = (longlong *)FUN_23e954670(param_1,plVar2,DAT_23eea8220,&local_78);
                  if (plVar11 == (longlong *)0x0) {
                    local_88 = *(longlong **)(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar14 = 0x6e;
                    uVar15 = 0x6e;
                    local_90 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar12 = *plVar12 + -1;
                    lVar10 = *plVar12;
                    goto joined_r0x00023e13187f;
                  }
                  *(undefined4 *)(plVar6 + 5) = 0x6e;
                  plVar13 = (longlong *)FUN_23e914090(param_1,plVar12,plVar11);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    goto LAB_23e13149c;
                  }
                }
                local_88 = *(longlong **)(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_90 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar14 = 0x6e;
              }
            }
          }
          goto LAB_23e1310ff;
        }
        local_88 = *(longlong **)(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plVar18 = (longlong *)0x0;
      uVar14 = 0x6a;
      goto LAB_23e1310ff;
    }
    plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
      DAT_23ed6a4c0 = plVar11;
      goto LAB_23e130cd3;
    }
    PyErr_PrintEx(0);
    uVar14 = SUB84(plVar11,0);
    Py_Exit(1);
    local_98 = plVar12;
LAB_23e1316c8:
    plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  plVar12[3] = (longlong)plVar6;
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
  pcVar17 = _PyRuntime_exref;
  *(undefined4 *)(plVar12 + 4) = 0xffffffff;
  lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
  lVar16 = plVar12[-1];
  puVar5 = *(undefined8 **)(lVar10 + 8);
  *puVar5 = plVar12 + -2;
  plVar12[-2] = lVar10;
  plVar12[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar5;
  lVar16 = *plVar19;
  *(longlong **)(lVar10 + 8) = plVar12 + -2;
  plVar12[2] = (longlong)plVar19;
  plVar11 = plVar12;
  if (lVar16 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
LAB_23e1311b3:
  FUN_23e8bba40(plVar6,"oooooo",plVar2,plVar3,plVar4,plVar9,local_98,plVar18);
  if (_DAT_23eeaadb0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eeaadb0 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar10 + 0x28);
  plVar12 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((local_98 != (longlong *)0x0) &&
     (lVar10 = *local_98, *local_98 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_98[1] + 0x30))(local_98);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_88,local_90,plVar11);
  return (code *)0x0;
}
