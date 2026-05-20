/* ===== 23c6350e0 license.license_client:355 ===== */
/* ghidra_name=FUN_23c6350e0 entry=23c6350e0 size=4762 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c6350e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  code *pcVar16;
  undefined4 uVar17;
  longlong *in_R10;
  code *in_R11;
  code *pcStack_d0;
  longlong **pplStack_c8;
  code *pcStack_b8;
  longlong *plStack_b0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23ee29c70;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23ee29c70 == (longlong *)0x0) {
LAB_23c635129:
    _DAT_23ee29c70 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c68,DAT_23ee29d18,0x18);
  }
  else {
    lVar8 = *_DAT_23ee29c70;
    if (1 < lVar8) {
      *_DAT_23ee29c70 = lVar8 + -1;
      goto LAB_23c635129;
    }
    if (_DAT_23ee29c70[2] != 0) {
      *_DAT_23ee29c70 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23c635129;
    }
  }
  plVar5 = _DAT_23ee29c70;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ee29c70 + 9;
  lVar3 = *(longlong *)(lVar8 + 8);
  _DAT_23ee29c70[0xf] = lVar3;
  *(longlong **)(lVar8 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  lVar8 = FUN_23ead5f40();
  if (lVar8 == 0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
    plVar10 = plStack_78;
    pcVar16 = pcStack_70;
    if (plStack_68 != (longlong *)0x0) {
      plVar9 = (longlong *)plStack_68[3];
      plVar11 = plStack_68;
      goto joined_r0x00023c6356dc;
    }
LAB_23c635970:
    pcStack_d0 = _PyRuntime_exref;
    plVar9 = (longlong *)&DAT_23ed6a4f8;
    iVar7 = 0x165;
LAB_23c63576b:
    plVar12 = (longlong *)*plVar9;
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      *plVar9 = *plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar8 = *(longlong *)(pcStack_d0 + 0x1f8);
    *(int *)((longlong)plVar12 + 0x24) = iVar7;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar3 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar8 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    pcVar14 = pcVar16;
    goto LAB_23c6355c0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23ee28548);
  pcVar16 = _DAT_23ee288a0;
  if (plVar9 == (longlong *)0x0) {
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar10 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar16 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plVar11 == (longlong *)0x0) goto LAB_23c635970;
    plVar9 = (longlong *)plVar11[3];
joined_r0x00023c6356dc:
    pcVar14 = pcVar16;
    plVar12 = plVar11;
    if (plVar5 == plVar9) goto LAB_23c6355c0;
    plVar9 = (longlong *)&DAT_23ed6a4f8;
    uVar17 = 0x165;
    pcStack_d0 = _PyRuntime_exref;
  }
  else {
    lVar8 = *(longlong *)(param_1 + 0x10);
    plVar12 = *(longlong **)(lVar8 + 0xe20);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar3 = plVar12[3];
      *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
      *(longlong *)(lVar8 + 0xe20) = lVar3;
      *plVar12 = 1;
    }
    pcStack_d0 = _PyRuntime_exref;
    plVar12[4] = 0;
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d0 + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar8 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    plVar10 = DAT_23ed6a4c0;
    *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
    plVar12[3] = (longlong)pcVar16;
    pcVar14 = DAT_23ed6cd28;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar10 == (longlong *)0x0) goto LAB_23c635f10;
      *plVar10 = *plVar10 + 1;
      DAT_23ed6a4c0 = plVar10;
    }
    pplStack_c8 = &plStack_78;
    pcStack_70 = pcVar14;
    plStack_78 = plVar2;
    lVar8 = FUN_23e94ed00(param_1,plVar10,pplStack_c8);
    if (lVar8 == 0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar16 = *(code **)(param_1 + 0x68);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
joined_r0x00023c635758:
      if (plVar11 == (longlong *)0x0) {
LAB_23c63575e:
        plVar9 = (longlong *)&DAT_23ed6a4f8;
        iVar7 = 0x165;
        goto LAB_23c63576b;
      }
      plVar9 = (longlong *)plVar11[3];
    }
    else {
      plVar12[4] = lVar8;
      pcStack_b8 = PyUnicode_Join_exref;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar10 != (longlong *)0x0) {
        *(undefined4 *)(plVar5 + 5) = 0x165;
        plVar11 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar10 = *(longlong **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar16 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto joined_r0x00023c635758;
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *(undefined4 *)(plVar5 + 5) = 0x168;
        plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23ee28558);
        if (plVar10 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar10 = *(longlong **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar16 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plVar11 == (longlong *)0x0) {
            plVar9 = (longlong *)&DAT_23ed6a4f8;
            iVar7 = 0x168;
            goto LAB_23c63576b;
          }
          pcVar14 = pcVar16;
          plVar12 = plVar11;
          if ((longlong *)plVar11[3] == plVar5) goto LAB_23c6355c0;
          plVar9 = (longlong *)&DAT_23ed6a4f8;
          uVar17 = 0x168;
          goto LAB_23c63552e;
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283e8);
        if (plVar9 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar10 = *(longlong **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar16 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          iVar7 = FUN_23a35f020(plVar9);
          lVar8 = *plVar9 + -1;
          if (iVar7 != -1) {
            *plVar9 = lVar8;
            if (lVar8 == 0) {
              (**(code **)(plVar9[1] + 0x30))();
            }
            pcVar16 = _Py_NoneStruct_exref;
            if (iVar7 == 0) {
LAB_23c6353d0:
              lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar10 = *(longlong **)(lVar8 + 0x28);
              plVar5 = (longlong *)plVar10[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
              *(undefined4 *)(plVar10 + 8) = 0xffffffff;
              if (plVar5 != (longlong *)0x0) {
                plVar10[2] = 0;
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))();
                }
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
              plVar10[0xf] = 0;
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 == 0) {
                (**(code **)(plVar2[1] + 0x30))(plVar2);
                return pcVar16;
              }
              return pcVar16;
            }
            *(undefined4 *)(plVar5 + 5) = 0x16d;
            plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23ee283e8,plVar2);
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              goto LAB_23c6353d0;
            }
            auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            pcVar16 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_b0 = *(longlong **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_b0 != (longlong *)0x0) {
              *plStack_b0 = *plStack_b0 + 1;
            }
            pcVar14 = DAT_23ed6a4f8;
            plVar9 = (longlong *)&DAT_23ed6a4f8;
            in_R11 = (code *)0x0;
            apcStack_88[0] = pcVar16;
            if (pcVar16 == (code *)0x0) goto LAB_23c635f23;
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar6 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar6;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            plVar9 = (longlong *)&DAT_23ed6a4f8;
            lVar8 = *(longlong *)(pcVar14 + -8);
            *(longlong **)(pcVar14 + 0x18) = plVar5;
            *plVar5 = *plVar5 + 1;
            *(longlong *)(pcVar14 + 0x20) = 0x16dffffffff;
            lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d0 + 0x1f8) + 0x10) + 0x2e8);
            puVar4 = *(undefined8 **)(lVar3 + 8);
            *puVar4 = pcVar14 + -0x10;
            *(longlong *)(pcVar14 + -0x10) = lVar3;
            *(ulonglong *)(pcVar14 + -8) = (ulonglong)puVar4 | (ulonglong)((uint)lVar8 & 3);
            *(code **)(lVar3 + 8) = pcVar14 + -0x10;
            *(code **)(pcVar14 + 0x10) = pcVar16;
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
            if ((apcStack_88[0] != (code *)0x0) &&
               (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
               *(longlong *)apcStack_88[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
            }
LAB_23c635b68:
            pcVar16 = _Py_NoneStruct_exref;
            apcStack_88[0] = pcVar14;
            if (((code *)auStack_98._0_8_ != (code *)0x0) &&
               ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
              FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
            }
            plVar10 = *(longlong **)(auStack_98._8_8_ + 0x28);
            if ((apcStack_88[0] != pcVar16) &&
               (in_R11 = apcStack_88[0], apcStack_88[0] != (code *)0x0)) {
              *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
            }
            *(code **)(auStack_98._8_8_ + 0x28) = in_R11;
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))();
            }
            plVar10 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))();
            }
            *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
            if (*(longlong *)auStack_98._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
            }
            if ((apcStack_88[0] != (code *)0x0) &&
               (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
               *(longlong *)apcStack_88[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
            }
            apcStack_88[0] = (code *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                  *(undefined8 *)PyExc_Exception_exref);
            if (iVar7 == 0) {
              pcVar14 = *(code **)(param_1 + 0x138);
              if ((pcVar14 == pcVar16) || (pcVar14 == (code *)0x0)) {
                plVar10 = *(longlong **)PyExc_RuntimeError_exref;
                pcVar16 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar14 = *(code **)(param_1 + 0x138);
                iVar7 = 0x16c;
                *plVar10 = *plVar10 + 1;
                *(longlong **)(param_1 + 0x138) = plStack_b0;
                if ((pcVar14 == (code *)0x0) ||
                   (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 != 0))
                goto LAB_23c63576b;
LAB_23c6362d9:
                (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
                if (iVar7 != 0) goto LAB_23c63576b;
              }
              else {
                plVar10 = *(longlong **)(pcVar14 + 8);
                plVar11 = *(longlong **)(pcVar14 + 0x28);
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                *plVar10 = *plVar10 + 1;
                pcVar16 = pcVar14;
                if (plVar11 != (longlong *)0x0) {
                  *plVar11 = *plVar11 + 1;
                  if (plVar5 == (longlong *)plVar11[3]) {
                    *(undefined4 *)(plVar5 + 5) = *(undefined4 *)((longlong)plVar11 + 0x24);
                  }
                  *(longlong **)(param_1 + 0x138) = plStack_b0;
                  *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
                  if (*(longlong *)pcVar14 == 0) {
                    (*(code *)plVar10[6])(pcVar14);
                    iVar7 = 0;
                    goto LAB_23c636063;
                  }
                  plVar12 = plVar11;
                  if ((longlong *)plVar11[3] != plVar5) goto LAB_23c636076;
                  goto LAB_23c6355c0;
                }
                *(longlong **)(param_1 + 0x138) = plStack_b0;
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
                if (*(longlong *)pcVar14 == 0) {
                  iVar7 = 0;
                  goto LAB_23c6362d9;
                }
              }
              iVar7 = (int)plVar5[5];
              goto LAB_23c63576b;
            }
            plVar12 = *(longlong **)(param_1 + 0x138);
            *plVar12 = *plVar12 + 1;
            lVar8 = FUN_23ead5f40();
            if (lVar8 == 0) {
              FUN_23e915740(param_1,pplStack_c8,DAT_23ee283f8);
              plVar11 = plStack_68;
              plVar10 = plStack_78;
              pcVar16 = pcStack_70;
              goto LAB_23c636130;
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(lVar8,DAT_23ee284c0);
            in_R11 = _DAT_23ee288a8;
            if (plVar13 == (longlong *)0x0) {
              plVar10 = *(longlong **)(param_1 + 0x60);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar16 = *(code **)(param_1 + 0x68);
              goto LAB_23c636130;
            }
            lVar8 = *(longlong *)(param_1 + 0x10);
            plVar15 = *(longlong **)(lVar8 + 0xe20);
            if (plVar15 == (longlong *)0x0) {
              plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar3 = plVar15[3];
              *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
              *(longlong *)(lVar8 + 0xe20) = lVar3;
              *plVar15 = 1;
            }
            plVar15[4] = 0;
            lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d0 + 0x1f8) + 0x10) + 0x2e8);
            lVar3 = plVar15[-1];
            puVar4 = *(undefined8 **)(lVar8 + 8);
            *puVar4 = plVar15 + -2;
            plVar15[-2] = lVar8;
            plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar8 + 8) = plVar15 + -2;
            plVar10 = DAT_23ed6a4c0;
            *(longlong *)in_R11 = *(longlong *)in_R11 + 1;
            plVar15[3] = (longlong)in_R11;
            pcVar14 = DAT_23ed6cd28;
            if (plVar10 != (longlong *)0x0) goto LAB_23c635d99;
            in_R10 = plVar9;
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 == (longlong *)0x0) {
LAB_23c635f10:
              plVar9 = in_R10;
              PyErr_PrintEx(0);
              pcVar14 = (code *)Py_Exit(1);
LAB_23c635f23:
              if (pcVar14 == (code *)0x0) {
                pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                pcVar16 = apcStack_88[0];
              }
              else {
                *plVar9 = *(longlong *)pcVar14;
                *(longlong *)pcVar14 = 1;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong *)(pcVar14 + 0x10) = 0;
              *(longlong **)(pcVar14 + 0x18) = plVar5;
              *plVar5 = *plVar5 + 1;
              *(longlong *)(pcVar14 + 0x20) = 0x16dffffffff;
              lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d0 + 0x1f8) + 0x10) + 0x2e8)
              ;
              lVar3 = *(longlong *)(pcVar14 + -8);
              puVar4 = *(undefined8 **)(lVar8 + 8);
              *puVar4 = pcVar14 + -0x10;
              *(longlong *)(pcVar14 + -0x10) = lVar8;
              *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
              *(code **)(lVar8 + 8) = pcVar14 + -0x10;
              if ((pcVar16 != (code *)0x0) &&
                 (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
                (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
              }
              goto LAB_23c635b68;
            }
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
LAB_23c635d99:
            pcStack_70 = pcVar14;
            plStack_78 = plVar12;
            lVar8 = FUN_23e94ed00(param_1,plVar10,pplStack_c8);
            if (lVar8 == 0) {
              plVar10 = *(longlong **)(param_1 + 0x60);
              pcVar16 = *(code **)(param_1 + 0x68);
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
            }
            else {
              plVar15[4] = lVar8;
              plVar10 = (longlong *)(*pcStack_b8)(DAT_23ed6cd28,plVar15);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (plVar10 == (longlong *)0x0) {
                plVar10 = *(longlong **)(param_1 + 0x60);
                pcVar16 = *(code **)(param_1 + 0x68);
                plVar11 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0(plVar13);
                }
              }
              else {
                *(undefined4 *)(plVar5 + 5) = 0x16f;
                plVar11 = (longlong *)FUN_23e914090(param_1,plVar13,plVar10);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar11 != (longlong *)0x0) {
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  plVar10 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plStack_b0;
                  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                    (**(code **)(plVar10[1] + 0x30))();
                  }
                  goto LAB_23c6353d0;
                }
                plVar10 = *(longlong **)(param_1 + 0x60);
                plVar11 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar16 = *(code **)(param_1 + 0x68);
              }
            }
LAB_23c636130:
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            plVar12 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plStack_b0;
            pcVar14 = pcVar16;
            if (plVar12 == (longlong *)0x0) {
              if (plVar11 == (longlong *)0x0) {
LAB_23c6363fd:
                iVar7 = 0x16f;
                goto LAB_23c63576b;
              }
              plVar13 = (longlong *)plVar11[3];
joined_r0x00023c6361dd:
              plVar12 = plVar11;
              if (plVar5 == plVar13) goto LAB_23c6355c0;
            }
            else {
              *plVar12 = *plVar12 + -1;
              if (*plVar12 != 0) {
                if (plVar11 == (longlong *)0x0) goto LAB_23c6363fd;
                plVar13 = (longlong *)plVar11[3];
                goto joined_r0x00023c6361dd;
              }
              (**(code **)(plVar12[1] + 0x30))();
              iVar7 = 0x16f;
              if (plVar11 == (longlong *)0x0) goto LAB_23c63576b;
LAB_23c636063:
              plVar12 = plVar11;
              if ((longlong *)plVar11[3] == plVar5) goto LAB_23c6355c0;
              pcVar16 = pcVar14;
              if (iVar7 == 0) {
LAB_23c636076:
                uVar17 = (undefined4)plVar5[5];
                goto LAB_23c63552e;
              }
            }
            uVar17 = 0x16f;
            goto LAB_23c63552e;
          }
          plVar10 = *(longlong **)(param_1 + 0x60);
          pcVar16 = *(code **)(param_1 + 0x68);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar9 = lVar8;
          if (lVar8 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
        }
        if (plVar11 == (longlong *)0x0) {
          plVar9 = (longlong *)&DAT_23ed6a4f8;
          iVar7 = 0x16b;
          goto LAB_23c63576b;
        }
        pcVar14 = pcVar16;
        plVar12 = plVar11;
        if (plVar5 == (longlong *)plVar11[3]) goto LAB_23c6355c0;
        plVar9 = (longlong *)&DAT_23ed6a4f8;
        uVar17 = 0x16b;
        goto LAB_23c63552e;
      }
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar16 = *(code **)(param_1 + 0x68);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 != 0) goto joined_r0x00023c635758;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      if (plVar11 == (longlong *)0x0) goto LAB_23c63575e;
      plVar9 = (longlong *)plVar11[3];
    }
    pcVar14 = pcVar16;
    plVar12 = plVar11;
    if (plVar5 == plVar9) goto LAB_23c6355c0;
    plVar9 = (longlong *)&DAT_23ed6a4f8;
    uVar17 = 0x165;
  }
LAB_23c63552e:
  plVar12 = (longlong *)*plVar9;
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    *plVar9 = *plVar12;
    *plVar12 = 1;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  plVar12[3] = (longlong)plVar5;
  *plVar5 = *plVar5 + 1;
  lVar8 = *(longlong *)(pcStack_d0 + 0x1f8);
  *(undefined4 *)((longlong)plVar12 + 0x24) = uVar17;
  *(undefined4 *)(plVar12 + 4) = 0xffffffff;
  lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
  lVar3 = plVar12[-1];
  puVar4 = *(undefined8 **)(lVar8 + 8);
  *puVar4 = plVar12 + -2;
  plVar12[-2] = lVar8;
  plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  lVar3 = *plVar11;
  *(longlong **)(lVar8 + 8) = plVar12 + -2;
  plVar12[2] = (longlong)plVar11;
  pcVar14 = pcVar16;
  if (lVar3 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23c6355c0:
  FUN_23e8bba40(plVar5,&DAT_23ec47adc,plVar1,plVar2,0);
  if (_DAT_23ee29c70 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23ee29c70 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar8 + 0x28);
  plVar9 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar10,pcVar14,plVar12);
  return (code *)0x0;
}
