/* ===== 23e800240 workers.fishing.memory_reeling:MemoryReelingTracker.start ===== */
/* ghidra_name=FUN_23e800240 entry=23e800240 size=6359 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e800240(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  longlong lVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  longlong *local_c8;
  undefined1 local_98 [16];
  longlong *local_88;
  longlong *local_78;
  code *local_70;
  longlong *local_68;
  undefined4 uVar20;
  
  plVar7 = _DAT_23eede930;
  plVar1 = (longlong *)*param_3;
  local_88 = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  if (_DAT_23eede930 == (longlong *)0x0) {
LAB_23e800297:
    _DAT_23eede930 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede958,DAT_23eedd0f8);
  }
  else {
    lVar9 = *_DAT_23eede930;
    if (1 < lVar9) {
      *_DAT_23eede930 = lVar9 + -1;
      goto LAB_23e800297;
    }
    if (_DAT_23eede930[2] != 0) {
      *_DAT_23eede930 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e800297;
    }
  }
  plVar2 = _DAT_23eede930;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eede930 + 9;
  lVar21 = *(longlong *)(lVar9 + 8);
  _DAT_23eede930[0xf] = lVar21;
  *(longlong **)(lVar9 + 8) = plVar7;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar22 = _DAT_23eedd1e8;
  *(undefined4 *)(plVar2 + 8) = 0;
  *(undefined4 *)(plVar2 + 5) = 0x7f;
  plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar22);
  if (plVar7 == (longlong *)0x0) {
LAB_23e80048b:
    local_88 = *(longlong **)(param_1 + 0x70);
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    uVar19 = 0x7f;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8004b4:
    uVar20 = uVar19;
    if (local_88 == (longlong *)0x0) {
LAB_23e800920:
      plVar7 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar12 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar12;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar8 = _PyRuntime_exref;
      plVar7[2] = 0;
      plVar7[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar9 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)(plVar7 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)((longlong)plVar7 + 0x24) = uVar20;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar21 = plVar7[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar7 + -2;
      plVar7[-2] = lVar9;
      plVar7[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar9 + 8) = plVar7 + -2;
      if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
        (**(code **)(local_88[1] + 0x30))(local_88);
      }
      goto LAB_23e800569;
    }
  }
  else {
    cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd130,plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (cVar5 == '\0') goto LAB_23e80048b;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd130);
    if (plVar7 != (longlong *)0x0) {
      iVar6 = FUN_23a35f020(plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      lVar9 = _DAT_23eedd1f8;
      uVar22 = _DAT_23eedd1f0;
      if (iVar6 == -1) goto LAB_23e8008e8;
      if (iVar6 == 0) {
        *(undefined4 *)(plVar2 + 5) = 0x81;
        plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,uVar22,*(undefined8 *)(lVar9 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_88 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x81;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e8004b4;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar9 = *(longlong *)_Py_FalseStruct_exref;
        pcVar8 = _Py_FalseStruct_exref;
LAB_23e8003fa:
        *(longlong *)pcVar8 = lVar9 + 1;
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar9 + 0x28);
        plVar2 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar7 + 8) = 0xffffffff;
        if (plVar2 != (longlong *)0x0) {
          plVar7[2] = 0;
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))();
          }
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        plVar7[0xf] = 0;
LAB_23e800451:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar8;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar8;
      }
      lVar9 = FUN_23e8dcc30();
      if (lVar9 == 0) {
        uVar19 = 0x84;
        FUN_23e915740(param_1,local_98,DAT_23eedd200);
      }
      else {
        plVar7 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd208);
        if (plVar7 == (longlong *)0x0) goto LAB_23e8009d0;
        lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
        if (*(char *)(lVar9 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd210);
          if (plVar12 == (longlong *)0x0) goto LAB_23e800a50;
          lVar21 = *plVar12;
LAB_23e800a3c:
          if (lVar21 == 0) goto LAB_23e800a50;
LAB_23e800706:
          lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar9 + 10) == '\0') {
            plVar12 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd218);
            if (plVar12 == (longlong *)0x0) goto LAB_23e800b00;
            lVar9 = *plVar12;
LAB_23e800aec:
            if (lVar9 == 0) goto LAB_23e800b00;
          }
          else {
            iVar6 = *(int *)(lVar9 + 0xc);
            if (*(int *)(lVar9 + 0xc) == 0) {
              *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
              iVar6 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (_DAT_23ec155dc != iVar6) {
              _DAT_23ec155dc = iVar6;
              _DAT_23eede928 =
                   FUN_23e8cbd60(lVar9,_DAT_23eedd218,*(undefined8 *)(_DAT_23eedd218 + 0x18));
            }
            if (-1 < _DAT_23eede928) {
              lVar15 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
              if (*(longlong *)(lVar15 + 8 + _DAT_23eede928 * 0x10) != 0) goto LAB_23e800773;
              _DAT_23eede928 =
                   FUN_23e8cbd60(lVar9,_DAT_23eedd218,*(undefined8 *)(_DAT_23eedd218 + 0x18));
              if (-1 < _DAT_23eede928) {
                lVar9 = *(longlong *)(lVar15 + 8 + _DAT_23eede928 * 0x10);
                goto LAB_23e800aec;
              }
            }
LAB_23e800b00:
            plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd218);
            lVar9 = _DAT_23eedd218;
            if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) goto LAB_23e800a83;
          }
LAB_23e800773:
          plVar12 = (longlong *)FUN_23e8c1360(lVar21);
          if (plVar12 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_88 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x84;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar7 = *plVar7 + -1;
            lVar9 = *plVar7;
joined_r0x00023e80111e:
            if (lVar9 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
          }
          else {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd130);
            if (plVar10 == (longlong *)0x0) {
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_88 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 != 0) goto LAB_23e800be0;
              uVar19 = 0x84;
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            else {
              *(undefined4 *)(plVar2 + 5) = 0x84;
              pcVar8 = _Py_FalseStruct_exref;
              local_70 = _Py_FalseStruct_exref;
              local_78 = plVar12;
              local_68 = plVar10;
              plVar11 = (longlong *)FUN_23e956150(param_1,plVar7,&local_78);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 != (longlong *)0x0) {
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd138,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (cVar5 != '\0') {
                  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd138);
                  if (plVar7 != (longlong *)0x0) {
                    iVar6 = FUN_23a35f020(plVar7);
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    lVar9 = _DAT_23eedd220;
                    uVar22 = _DAT_23eedd1f0;
                    if (iVar6 != -1) {
                      if (iVar6 == 0) {
                        *(undefined4 *)(plVar2 + 5) = 0x86;
                        plVar7 = (longlong *)
                                 FUN_23e915840(param_1,plVar1,uVar22,*(undefined8 *)(lVar9 + 0x18));
                        if (plVar7 != (longlong *)0x0) {
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
LAB_23e8008c5:
                          lVar9 = *(longlong *)pcVar8;
                          goto LAB_23e8003fa;
                        }
                        local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_88 = *(longlong **)(param_1 + 0x70);
                        uVar19 = 0x86;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e8004b4;
                      }
                      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd228);
                      if (plVar7 != (longlong *)0x0) {
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd130);
                        if (plVar12 == (longlong *)0x0) {
                          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_88 = *(longlong **)(param_1 + 0x70);
                          uVar19 = 0x89;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar7 = *plVar7 + -1;
                          lVar9 = *plVar7;
                          goto joined_r0x00023e80111e;
                        }
                        *(undefined4 *)(plVar2 + 5) = 0x89;
                        plVar10 = (longlong *)FUN_23e914090(param_1,plVar7,plVar12);
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        if (plVar10 != (longlong *)0x0) {
                          cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd140,plVar10);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (cVar5 != '\0') {
                            plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd140);
                            if (plVar7 != (longlong *)0x0) {
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eedd230);
                              *plVar7 = *plVar7 + -1;
                              if (*plVar7 == 0) {
                                (**(code **)(plVar7[1] + 0x30))(plVar7);
                              }
                              if (plVar12 != (longlong *)0x0) {
                                *(undefined4 *)(plVar2 + 5) = 0x8a;
                                plVar7 = (longlong *)FUN_23e91a870(param_1,plVar12);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                                }
                                if (plVar7 != (longlong *)0x0) {
                                  plVar12 = (longlong *)FUN_23ebf7180(plVar7);
                                  *plVar7 = *plVar7 + -1;
                                  if (*plVar7 == 0) {
                                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                                  }
                                  if (plVar12 != (longlong *)0x0) {
                                    lVar9 = *(longlong *)(param_1 + 0x10);
                                    if (*(int *)(lVar9 + 0x1188) == 0) {
                                      plVar7 = (longlong *)FUN_23a33a530(PyList_Type_exref);
                                    }
                                    else {
                                      iVar6 = *(int *)(lVar9 + 0x1188) + -1;
                                      *(int *)(lVar9 + 0x1188) = iVar6;
                                      plVar7 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar6 * 8);
                                      *plVar7 = 1;
                                    }
                                    pcVar4 = _PyRuntime_exref;
                                    plVar7[2] = 0;
                                    plVar7[4] = 0;
                                    lVar9 = *(longlong *)(pcVar4 + 0x1f8);
                                    plVar7[3] = 0;
                                    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
                                    lVar21 = plVar7[-1];
                                    puVar3 = *(undefined8 **)(lVar9 + 8);
                                    *puVar3 = plVar7 + -2;
                                    plVar7[-2] = lVar9;
                                    plVar7[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
                                    *(longlong **)(lVar9 + 8) = plVar7 + -2;
                                    plVar10 = (longlong *)0x0;
                                    plVar11 = (longlong *)0x0;
                                    plVar16 = (longlong *)0x0;
                                    while( true ) {
                                      pcVar4 = *(code **)(plVar12[1] + 0xe0);
                                      if (pcVar4 == (code *)0x0) break;
                                      local_c8 = (longlong *)(*pcVar4)(plVar12);
                                      if (local_c8 == (longlong *)0x0) goto LAB_23e801446;
                                      if ((plVar10 != (longlong *)0x0) &&
                                         (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                      }
                                      plVar10 = (longlong *)FUN_23a388310(local_c8);
                                      if (plVar10 == (longlong *)0x0) {
                                        uVar22 = *(undefined8 *)(param_1 + 0x60);
                                        uVar23 = *(undefined8 *)(param_1 + 0x68);
                                        plVar17 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e80120c;
                                      }
                                      plVar13 = (longlong *)
                                                (**(code **)(plVar10[1] + 0xe0))(plVar10);
                                      if ((plVar13 == (longlong *)0x0) &&
                                         (plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,2),
                                         plVar17 = local_88, plVar13 == (longlong *)0x0)) {
                                        uVar22 = local_98._0_8_;
                                        uVar23 = local_98._8_8_;
                                        local_98 = (undefined1  [16])0x0;
                                        local_88 = (longlong *)0x0;
                                        *plVar10 = *plVar10 + -1;
                                        if (*plVar10 == 0) {
                                          FUN_23a334bc0(plVar10);
                                        }
                                        goto LAB_23e80120c;
                                      }
                                      plVar14 = (longlong *)
                                                (**(code **)(plVar10[1] + 0xe0))(plVar10);
                                      if ((plVar14 == (longlong *)0x0) &&
                                         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,2),
                                         plVar14 == (longlong *)0x0)) {
                                        lVar9 = *plVar10;
LAB_23e8016a3:
                                        plVar17 = local_88;
                                        uVar22 = local_98._0_8_;
                                        uVar23 = local_98._8_8_;
                                        local_98 = (undefined1  [16])0x0;
                                        local_88 = (longlong *)0x0;
                                        *plVar10 = lVar9 + -1;
                                        if (lVar9 + -1 == 0) {
                                          FUN_23a334bc0(plVar10);
                                        }
                                        local_88 = (longlong *)0x0;
                                        local_98 = (undefined1  [16])0x0;
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        if ((plVar14 != (longlong *)0x0) &&
                                           (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        goto LAB_23e80120c;
                                      }
                                      cVar5 = FUN_23a3884a0(param_1,local_98,plVar10);
                                      lVar9 = *plVar10;
                                      if (cVar5 == '\0') goto LAB_23e8016a3;
                                      *plVar10 = lVar9 + -1;
                                      if (lVar9 + -1 == 0) {
                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                      }
                                      lVar9 = *plVar13;
                                      *plVar13 = lVar9 + 1;
                                      if (plVar16 != (longlong *)0x0) {
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                                        }
                                        lVar9 = *plVar13 + -1;
                                      }
                                      *plVar13 = lVar9;
                                      if (lVar9 == 0) {
                                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                                      }
                                      lVar9 = *plVar14;
                                      *plVar14 = lVar9 + 1;
                                      if (plVar11 != (longlong *)0x0) {
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                                        }
                                        lVar9 = *plVar14 + -1;
                                      }
                                      *plVar14 = lVar9;
                                      if (lVar9 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      }
                                      lVar9 = *(longlong *)(param_1 + 0x10);
                                      plVar10 = *(longlong **)(lVar9 + 0xe20);
                                      if (plVar10 == (longlong *)0x0) {
                                        plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                                      }
                                      else {
                                        lVar21 = plVar10[3];
                                        *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
                                        *(longlong *)(lVar9 + 0xe20) = lVar21;
                                        *plVar10 = 1;
                                      }
                                      pcVar4 = _PyRuntime_exref;
                                      plVar10[4] = 0;
                                      lVar9 = *(longlong *)
                                               (*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10)
                                               + 0x2e8);
                                      lVar21 = plVar10[-1];
                                      puVar3 = *(undefined8 **)(lVar9 + 8);
                                      *puVar3 = plVar10 + -2;
                                      plVar10[-2] = lVar9;
                                      plVar10[-1] = (ulonglong)((uint)lVar21 & 3) |
                                                    (ulonglong)puVar3;
                                      *(longlong **)(lVar9 + 8) = plVar10 + -2;
                                      *plVar13 = *plVar13 + 1;
                                      plVar10[3] = (longlong)plVar13;
                                      lVar9 = FUN_23e8c09e0(plVar13,plVar14);
                                      plVar16 = plVar13;
                                      plVar11 = plVar14;
                                      if (lVar9 == 0) {
                                        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        local_88 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *plVar10 = *plVar10 + -1;
                                        plVar17 = local_88;
                                        uVar22 = local_98._0_8_;
                                        uVar23 = local_98._8_8_;
                                        if (*plVar10 == 0) {
                                          FUN_23a334bc0(plVar10);
                                          plVar17 = local_88;
                                          uVar22 = local_98._0_8_;
                                          uVar23 = local_98._8_8_;
                                        }
                                        goto LAB_23e80120c;
                                      }
                                      lVar21 = plVar7[2];
                                      lVar15 = plVar7[3];
                                      plVar10[4] = lVar9;
                                      lVar9 = lVar21 + 1;
                                      if ((plVar7[4] < lVar9) || (lVar9 < plVar7[4] >> 1)) {
                                        if (lVar9 == 0) {
                                          uVar18 = 0;
                                        }
                                        else {
                                          uVar18 = lVar21 + 7 + (lVar9 >> 3) & 0xfffffffffffffffc;
                                        }
                                        lVar15 = (*DAT_23ed6e610)(0);
                                        if (lVar15 == 0) {
                                          PyErr_NoMemory();
                                          goto LAB_23e8011f3;
                                        }
                                        plVar7[3] = lVar15;
                                        plVar7[2] = lVar9;
                                        plVar7[4] = uVar18;
                                      }
                                      else {
                                        plVar7[2] = lVar9;
                                      }
                                      *(longlong **)(lVar15 + lVar21 * 8) = plVar10;
                                      lVar9 = *(longlong *)(param_1 + 0x10);
                                      if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                                           (*(int *)(lVar9 + 0x78) != 0)) &&
                                          (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
                                         (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e8011f3;
                                      if (*(int *)(lVar9 + 0x68) == 0) {
                                        plVar17 = *(longlong **)(param_1 + 0x90);
                                      }
                                      else {
                                        PyEval_SaveThread();
                                        PyEval_AcquireThread(param_1);
                                        plVar17 = *(longlong **)(param_1 + 0x90);
                                      }
                                      plVar10 = local_c8;
                                      if (plVar17 != (longlong *)0x0) goto LAB_23e8012ed;
                                    }
                                    PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                                 "\'%s\' object is not an iterator",
                                                 *(undefined8 *)(plVar12[1] + 0x18));
LAB_23e801446:
                                    cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)
                                                                   PyExc_StopIteration_exref);
                                    if (cVar5 == '\0') {
                                      uVar22 = *(undefined8 *)(param_1 + 0x60);
                                      uVar23 = *(undefined8 *)(param_1 + 0x68);
                                      plVar17 = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      local_c8 = plVar10;
                                      goto LAB_23e80120c;
                                    }
                                    *plVar7 = *plVar7 + 1;
                                    lVar9 = *plVar12;
                                    *plVar12 = lVar9 + -1;
                                    if (lVar9 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    lVar9 = *plVar7;
                                    *plVar7 = lVar9 + -1;
                                    if (lVar9 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if ((plVar10 != (longlong *)0x0) &&
                                       (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    if ((plVar16 != (longlong *)0x0) &&
                                       (lVar9 = *plVar16, *plVar16 = lVar9 + -1, lVar9 + -1 == 0)) {
                                      FUN_23a334bc0();
                                    }
                                    if ((plVar11 != (longlong *)0x0) &&
                                       (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                                      FUN_23a334bc0(plVar11);
                                    }
                                    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd148,plVar7);
                                    lVar9 = *plVar7;
                                    *plVar7 = lVar9 + -1;
                                    if (lVar9 + -1 == 0) {
                                      FUN_23a334bc0(plVar7);
                                    }
                                    if (cVar5 == '\0') {
                                      local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                      local_88 = *(longlong **)(param_1 + 0x70);
                                      uVar19 = 0x8a;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      goto LAB_23e8004b4;
                                    }
                                    *(undefined4 *)(plVar2 + 5) = 0x8b;
                                    plVar7 = (longlong *)
                                             FUN_23e91bfe0(param_1,plVar1,_DAT_23eedd238);
                                    if (plVar7 != (longlong *)0x0) {
                                      cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd150,plVar7);
                                      *plVar7 = *plVar7 + -1;
                                      if (*plVar7 == 0) {
                                        FUN_23a334bc0(plVar7);
                                      }
                                      if (cVar5 != '\0') {
                                        plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd150);
                                        if (plVar7 != (longlong *)0x0) {
                                          iVar6 = FUN_23a35f020(plVar7);
                                          *plVar7 = *plVar7 + -1;
                                          if (*plVar7 == 0) {
                                            FUN_23a334bc0(plVar7);
                                          }
                                          lVar9 = _DAT_23eedd240;
                                          uVar22 = _DAT_23eedd1f0;
                                          if (iVar6 != -1) {
                                            if (iVar6 == 0) {
                                              *(undefined4 *)(plVar2 + 5) = 0x8d;
                                              plVar7 = (longlong *)
                                                       FUN_23e915840(param_1,plVar1,uVar22,
                                                                     *(undefined8 *)(lVar9 + 0x18));
                                              if (plVar7 == (longlong *)0x0) {
                                                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                local_88 = *(longlong **)(param_1 + 0x70);
                                                uVar19 = 0x8d;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                              else {
                                                *plVar7 = *plVar7 + -1;
                                                if (*plVar7 == 0) {
                                                  FUN_23a334bc0(plVar7);
                                                }
                                                *(undefined4 *)(plVar2 + 5) = 0x8e;
                                                plVar7 = (longlong *)
                                                         FUN_23e91bfe0(param_1,plVar1,_DAT_23eedd248
                                                                      );
                                                if (plVar7 != (longlong *)0x0) {
                                                  *plVar7 = *plVar7 + -1;
                                                  if (*plVar7 == 0) {
                                                    FUN_23a334bc0(plVar7);
                                                  }
                                                  goto LAB_23e8008c5;
                                                }
                                                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                local_88 = *(longlong **)(param_1 + 0x70);
                                                uVar19 = 0x8e;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                            }
                                            else {
                                              cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,
                                                                    _Py_NoneStruct_exref);
                                              if (cVar5 == '\0') {
                                                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                local_88 = *(longlong **)(param_1 + 0x70);
                                                uVar19 = 0x91;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                              else {
                                                cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd158);
                                                if (cVar5 == '\0') {
                                                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_88 = *(longlong **)(param_1 + 0x70);
                                                  uVar19 = 0x92;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  lVar9 = FUN_23e8dcd80();
                                                  if (lVar9 == 0) {
                                                    uVar19 = 0x93;
                                                    FUN_23e915740(param_1,local_98,_DAT_23eedd1a0);
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar2 + 5) = 0x93;
                                                    plVar7 = (longlong *)
                                                             FUN_23e91bfe0(param_1,lVar9);
                                                    if (plVar7 != (longlong *)0x0) {
                                                      cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1a8,
                                                                            plVar7);
                                                      *plVar7 = *plVar7 + -1;
                                                      if (*plVar7 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (cVar5 != '\0') {
                                                        *(undefined4 *)(plVar2 + 5) = 0x94;
                                                        plVar7 = (longlong *)
                                                                 FUN_23e91bfe0(param_1,plVar1,
                                                                               _DAT_23eedd250);
                                                        if (plVar7 != (longlong *)0x0) {
                                                          cVar5 = FUN_23e8d9ac0(plVar1,
                                                  _DAT_23eedd1c0,plVar7);
                                                  *plVar7 = *plVar7 + -1;
                                                  if (*plVar7 == 0) {
                                                    FUN_23a334bc0(plVar7);
                                                  }
                                                  if (cVar5 != '\0') {
                                                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                                    pcVar8 = _Py_TrueStruct_exref;
                                                    *(longlong *)_Py_TrueStruct_exref =
                                                         *(longlong *)_Py_TrueStruct_exref + 1;
                                                    goto LAB_23e800451;
                                                  }
                                                  }
                                                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_88 = *(longlong **)(param_1 + 0x70);
                                                  uVar19 = 0x94;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e8004b4;
                                                  }
                                                  }
                                                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_88 = *(longlong **)(param_1 + 0x70);
                                                  uVar19 = 0x93;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                }
                                              }
                                            }
                                            goto LAB_23e8004b4;
                                          }
                                        }
                                        local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                        local_88 = *(longlong **)(param_1 + 0x70);
                                        uVar19 = 0x8c;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e8004b4;
                                      }
                                    }
                                    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_88 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar19 = 0x8b;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e8004b4;
                                  }
                                }
                              }
                            }
                            uVar22 = *(undefined8 *)(param_1 + 0x60);
                            uVar23 = *(undefined8 *)(param_1 + 0x68);
                            plVar17 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e8012b9;
                          }
                        }
                      }
                      local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_88 = *(longlong **)(param_1 + 0x70);
                      uVar19 = 0x89;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e8004b4;
                    }
                  }
                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_88 = *(longlong **)(param_1 + 0x70);
                  uVar19 = 0x85;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e8004b4;
                }
              }
LAB_23e8009d0:
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_88 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0x84;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
          }
        }
        else {
          iVar6 = *(int *)(lVar9 + 0xc);
          if (*(int *)(lVar9 + 0xc) == 0) {
            *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
            iVar6 = DAT_23ec155d8;
            DAT_23ec155d8 = DAT_23ec155d8 + 1;
          }
          if (_DAT_23ec155d4 != iVar6) {
            _DAT_23ec155d4 = iVar6;
            _DAT_23eede920 =
                 FUN_23e8cbd60(lVar9,_DAT_23eedd210,*(undefined8 *)(_DAT_23eedd210 + 0x18));
          }
          if (-1 < _DAT_23eede920) {
            lVar15 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
            lVar21 = *(longlong *)(lVar15 + 8 + _DAT_23eede920 * 0x10);
            if (lVar21 != 0) goto LAB_23e800706;
            _DAT_23eede920 =
                 FUN_23e8cbd60(lVar9,_DAT_23eedd210,*(undefined8 *)(_DAT_23eedd210 + 0x18));
            if (-1 < _DAT_23eede920) {
              lVar21 = *(longlong *)(lVar15 + 8 + _DAT_23eede920 * 0x10);
              goto LAB_23e800a3c;
            }
          }
LAB_23e800a50:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd210);
          lVar9 = _DAT_23eedd210;
          if ((plVar12 != (longlong *)0x0) && (lVar21 = *plVar12, lVar21 != 0)) goto LAB_23e800706;
LAB_23e800a83:
          FUN_23e915740(param_1,local_98,lVar9);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            uVar19 = 0x84;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          else {
LAB_23e800be0:
            uVar19 = 0x84;
          }
        }
      }
      goto LAB_23e8004b4;
    }
LAB_23e8008e8:
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    uVar20 = 0x80;
    uVar19 = 0x80;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_88 == (longlong *)0x0) {
      local_88 = (longlong *)0x0;
      goto LAB_23e800920;
    }
  }
  plVar7 = local_88;
  plVar12 = DAT_23ed6a4f8;
  if ((longlong *)local_88[3] != plVar2) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar9 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar19;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar21 = plVar12[-1];
    puVar3 = *(undefined8 **)(lVar9 + 8);
    *puVar3 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    plVar7 = plVar12;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))();
    }
  }
LAB_23e800569:
  local_88 = plVar7;
  FUN_23e8bba40(plVar2,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eede930 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eede930 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar2 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88);
  return (code *)0x0;
LAB_23e8012ed:
  plVar10 = *(longlong **)(param_1 + 0x60);
  plVar13 = *(longlong **)(param_1 + 0x68);
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar17;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *plVar17 = *plVar17 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
LAB_23e8011f3:
  plVar17 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar22 = *(undefined8 *)(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar23 = *(undefined8 *)(param_1 + 0x68);
LAB_23e80120c:
  local_88 = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  lVar9 = *plVar12;
  *plVar12 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))();
  }
  lVar9 = *plVar7;
  *plVar7 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar7[1] + 0x30))();
  }
  if ((local_c8 != (longlong *)0x0) && (lVar9 = *local_c8, *local_c8 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_c8[1] + 0x30))();
  }
  local_88 = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23e8012b9:
  uVar19 = 0x8a;
  local_98._8_8_ = uVar23;
  local_98._0_8_ = uVar22;
  local_88 = plVar17;
  goto LAB_23e8004b4;
}
